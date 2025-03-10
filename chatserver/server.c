#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <signal.h>
#include <stdbool.h>
#include <ctype.h>
#include "user.h"
#include "chatroom.h"
#include "friends.h"
#include "chat11.h"

OnlineUser onlineUsers[MAX_CLIENTS];
int onlineUserCount = 0;
static int next_id;

static _Atomic unsigned int cli_count = 0;

client_t* clients[MAX_CLIENTS];
client_t* user_list = NULL;
chatroom_t* chatroom_list = NULL;

pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

/* Add clients to queue*/
void queue_add(client_t* cl) {
    pthread_mutex_lock( &clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; ++i)
        if (!clients[i]) {
            clients[i] = cl;
            break;
        }
    pthread_mutex_unlock( &clients_mutex);
}

/* Remove clients to queue*/
void queue_remove(char* name) {
    pthread_mutex_lock( &clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; ++i)
        if (clients[i])
            if (strcpy(clients[i]->name, name) == 0) {
                clients[i] = NULL;
                break;
            }
    pthread_mutex_unlock( &clients_mutex);
}

/* Handle all communication with the client*/
void* handle_client(void* arg) {
    char buff_out[BUFFER_SZ];
    int leave_flag = 0;
    cli_count++;
    client_t* cli = (client_t* ) arg;
    Packet* packet = (Packet* ) malloc(sizeof(Packet));

    while (1) {
        if (recv(cli->sockfd, packet, sizeof(Packet), 0) <= 0) {
            onlineUserCount = removeOnlineUser(onlineUsers, onlineUserCount, cli->sockfd);
            save_all_messages(chatroom_list);
            save_user_rooms(user_list, "user_rooms.txt");
            save_friend_lists("friends_lists.txt");
            save_chatrooms_to_file(chatroom_list, "chatrooms.txt");
            leave_flag = 1;
            break;
        } else {
            // printf("%d %s %s %s\n", packet->command_type, packet->username, packet->password, packet->room_name);
            switch (packet->command_type) {
            case 0:
                handle_register(user_list, packet, next_id);
                send(cli->sockfd, packet, sizeof(Packet), 0);
                if (packet->status == 1) {
                    next_id ++;
                    strcpy(cli->name, packet->username);
                    onlineUserCount = addOnlineUser(onlineUsers, onlineUserCount, cli->sockfd, cli->name);
                    create_friend_list(cli->uid);
                }
                break;
            case 1:
                handle_login(user_list, packet, cli);
                send(cli->sockfd, packet, sizeof(Packet), 0);
                if (packet->status == 0)
                    leave_flag = 1;
                else {
                    strcpy(cli->name, packet->username);
                    onlineUserCount = addOnlineUser(onlineUsers, onlineUserCount, cli->sockfd, cli->name);
                    load_user_rooms(cli, user_list);
                    if (!get_friend_list_by_userid(cli->uid)) 
                        create_friend_list(cli->uid);
                }
                break;
            case 2: {
                chatroom_t* room = find_chatroom(chatroom_list, packet->room_name);
                if (room) {
                    send_message_to_chatroom(room, packet->message, cli->uid);
                    add_message_to_chatroom(room, cli->name, packet->message);
                } else {
                    strcpy(packet->message, "Room not found. Message not sent.\n");
                }}
                break;
            case 3: {
                handle_create_room( &chatroom_list, packet, cli);
                if (packet->status == 1) {
                    add_room_to_user(cli, user_list, packet->room_name, 1);
                    view_user_rooms(cli);
                }}
                break;
            case 4: {
                chatroom_t* room = find_chatroom(chatroom_list, packet->room_name);
                handle_join_room( &chatroom_list, packet, cli);
                send(cli->sockfd, packet, sizeof(Packet), 0);
                if (packet->status == 1)
                    send_old_messages(room, cli->sockfd);
                }
                break;
            case 5:
                view_online_users(onlineUsers, onlineUserCount, cli);
                break;
            case 6:{
                InvitePacket* invite = (InvitePacket* ) malloc(sizeof(InvitePacket));
                recv(cli->sockfd, invite, sizeof(InvitePacket), 0);
                chatroom_t* room = find_chatroom(chatroom_list, invite->room_name);
                handle_room_invitation(user_list, invite, room, cli->sockfd);
                }
                break;
            case 7:
                if (packet->status == 1) {
                    handle_accept_invitation( &chatroom_list, packet, cli);
                    add_room_to_user(cli, user_list, packet->room_name, 1);
                    view_user_rooms(cli);
                } else
                    handle_reject_invitation(user_list, packet, cli);
                break;
            case 8:
                chatroom_t* current_room = find_chatroom(chatroom_list, packet->room_name);
                view_room_users(current_room, cli->sockfd);
                break;
            case 9:
                handle_remove_member(chatroom_list, user_list, packet, cli);
                break;
            case 10:
                handle_leave_chatroom(chatroom_list, packet, cli);
                break;
            case 11:
                view_user_rooms(cli);
                break;
            case 12: {
                client_t* user = findUser(user_list, packet->username);
                send_friend_request(cli->uid, user->uid);
                }
                break;
            case 13: {
                client_t* user = findUser(user_list, packet->username);
                if (packet->status == 1)
                    accept_friend_request(user->uid, cli->uid);
                else 
                    decline_friend_request(cli->uid, user->uid);
                }
                break;
            case 14:
                view_friend_requests(user_list, cli);
                break;
            case 15:
                view_friend_list(user_list, cli, onlineUsers, onlineUserCount);
                break;
            case 16: {
                client_t* user = findUser(user_list, packet->username);
                printf("%d\n", user->uid);
                remove_friend(cli->uid, user->uid);
                // Xóa quan hệ ngược lại
                remove_friend(user->uid, cli->uid);
                }
                break;
            case 17:
                view_friend_online(user_list, cli, onlineUsers, onlineUserCount);
                break;
            case 21: {
            

                client_t *receiver = findUser(user_list, packet->username);
                send_private_message(cli, receiver, packet->message);
                }
            break;
            case 18: {// 0x15: Request private message
                client_t *receiver = findUser(user_list, packet->username);
                request_private_message(user_list, cli, receiver);
                }
            break;
            case 20: { // 0x17: Disconnect chat
                client_t *sender = findUser(user_list, cli->name);
                client_t *receiver = findUser(user_list, packet->username);
                disconnect_chat(sender, receiver);
            }
            break;
            case 19: { // 0x18: Accept chat request
                client_t *sender = findUser(user_list, cli->name);
                client_t *receiver = findUser(user_list, packet->username);
                if (packet->status == 1) {
                    accept_chat_request(sender, receiver);
                    retrieve_message(cli->sockfd, cli->name, receiver->name);
                    retrieve_message(receiver->sockfd, cli->name, receiver->name);
                    } 
            }
            break;
            }
        }
    }

    /* Delete client from queue and yield thread*/
    close(cli->sockfd);
    queue_remove(cli->name);
    free(cli);
    cli_count--;
    pthread_detach(pthread_self());

    return NULL;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char* ip = "127.0.0.1";
    int port = atoi(argv[1]);
    int option = 1;
    int listenfd = 0, connfd = 0;
    struct sockaddr_in serv_addr;
    struct sockaddr_in cli_addr;
    pthread_t tid;

    /* Socket settings*/
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip);
    serv_addr.sin_port = htons(port);

    /* Ignore pipe signals*/
    signal(SIGPIPE, SIG_IGN);

    if (setsockopt(listenfd, SOL_SOCKET, (SO_REUSEADDR), (char* ) &option, sizeof(option)) < 0) {
        perror("ERROR: setsockopt failed");
        return EXIT_FAILURE;
    }

    /* Bind*/
    if (bind(listenfd, (struct sockaddr* ) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR: Socket binding failed");
        return EXIT_FAILURE;
    }

    /* Listen*/
    if (listen(listenfd, 10) < 0) {
        perror("ERROR: Socket listening failed");
        return EXIT_FAILURE;
    }

    next_id = readFromFile( &user_list, USER_FILE, next_id) + 1;
    load_friend_lists("friends_lists.txt");
    load_chatrooms_from_file(&chatroom_list, user_list, "chatrooms.txt");
    load_all_messages(chatroom_list);

    while (1) {
        socklen_t clilen = sizeof(cli_addr);
        connfd = accept(listenfd, (struct sockaddr* ) &cli_addr, &clilen);

        /* Check if max clients is reached*/
        if ((cli_count + 1) == MAX_CLIENTS) {
            printf("Max clients reached. Rejected: ");
            // print_client_addr(cli_addr);
            printf(":%d\n", cli_addr.sin_port);
            close(connfd);
            continue;
        }

        /* Client settings*/
        client_t* cli = (client_t* ) malloc(sizeof(client_t));
        cli->address = cli_addr;
        cli->sockfd = connfd;

        /* Add client to the queue and fork thread*/
        queue_add(cli);
        pthread_create( &tid, NULL, &handle_client, (void* ) cli);

        /* Reduce CPU usage*/
        sleep(1);
    }

    return EXIT_SUCCESS;
}