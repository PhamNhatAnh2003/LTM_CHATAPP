#ifndef CHATROOM_H
#define CHATROOM_H

#include <pthread.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

#define MAX_CHATROOM 20
#define MAX_MESSAGES 2048

typedef struct {
    char sender[50];
    char content[1024];
    time_t timestamp; // Thời gian gửi
} message_t;

/*ChatRoom structure */
typedef struct chatroom_t {
    char room_name[32];
    client_t *admin;
    client_t *members[MAX_CLIENTS];
    int member_count;
    message_t messages[MAX_MESSAGES]; // Danh sách tin nhắn
    int message_count; // Số lượng tin nhắn
    struct chatroom_t *next;
} chatroom_t;

// 
typedef struct {
    char sender_name[50]; // Tên người gửi lời mời
    char target_name[50]; // Tên người nhận lời mời
    char room_name[50]; // Tên chatroom
} InvitePacket;

chatroom_t *create_chatroom(const char *room_name);
int is_admin(chatroom_t *room, client_t *client); 
void add_chatroom(chatroom_t **head, const char *room_name, client_t *client);
chatroom_t *find_chatroom(chatroom_t *head, const char *room_name);
void add_member_to_chatroom(chatroom_t *room, client_t *client);
void send_message_to_chatroom(chatroom_t *room, char *message, int sender_uid);
void handle_create_room(chatroom_t **chatroom_list, Packet *packet, client_t *cli);
void handle_join_room(chatroom_t **chatroom_list, Packet *packet, client_t *cli);
void handle_room_invitation(client_t *user_list, InvitePacket *invite, chatroom_t *room, int sockfd);
void handle_accept_invitation(chatroom_t **chatroom_list, Packet *packet, client_t *cli);
void handle_reject_invitation(client_t *user_list, Packet *packet, client_t *cli);
char* room_users(chatroom_t* room);
void view_room_users(chatroom_t *room, int client_sock);
void handle_remove_member(chatroom_t *chatroom_list, client_t *user_list, Packet *packet, client_t *cli);
void remove_member_from_chatroom(chatroom_t *room, client_t *client, client_t *requester, char *response);
void handle_leave_chatroom(chatroom_t *chatroom_list, Packet *packet, client_t *cli);
void delete_chatroom(chatroom_t**chatroom_list, chatroom_t*room);
void leave_chatroom(chatroom_t**chatroom_list, chatroom_t*room, client_t*client, char*response);
void save_chatrooms_to_file(chatroom_t *chatroom_list, const char *filename);
void load_chatrooms_from_file(chatroom_t **chatroom_list, client_t* user_list, const char *filename);
void send_old_messages(chatroom_t *room, int client_sock);
void add_message_to_chatroom(chatroom_t *room, const char *sender, const char *content);
void save_all_messages(chatroom_t *chatroom_list);
void save_messages_to_file(chatroom_t *room);
void load_messages_from_file(chatroom_t *room);
void load_all_messages(chatroom_t *chatroom_list);
void view_user_rooms(client_t *client);
void save_user_rooms(client_t *client_list, const char *filename);
void load_user_rooms(client_t *cli, client_t *client_list);

#endif // CHATROOM_H