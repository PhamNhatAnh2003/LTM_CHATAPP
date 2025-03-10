#ifndef USER_H
#define USER_H

#include <stdbool.h>
#include <pthread.h>
#include <ctype.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SZ 2048
#define MAX_CLIENTS 100
#define MAX_CHATROOM 20
#define USER_FILE "account.txt"

typedef struct client_t {
    struct sockaddr_in address;
    int sockfd;
    int uid;
    char name[32];
    char password[32];
    int status;
    char room_names[MAX_CHATROOM][50];
    int room_count; 
    int chatting_partner_id;
    struct client_t *next;
} client_t;

typedef struct Packet {
    int command_type;
    char username[32];
    char password[32];
    int status;
    char room_name[32];
    char message[BUFFER_SZ];
} Packet;

typedef struct {
    int socket;
    char username[50];
} OnlineUser;

client_t *createUser(int uid, char *name, char *password, int status);
void addUser(client_t **head, int uid, char *username, char *password, int status);
void freeUsers(client_t *head);
int readFromFile(client_t **head, const char *fn, int next_id);
void writeToFile(client_t *head, const char *fn);
client_t *findUser(client_t *head, char *name);
client_t* findUserById(client_t *head, int uid);
void updateStatus(client_t *head, char *username);
void updatePassword(client_t *head, char *username, char *newpass);
int checkInvalidPassword(char *password);
void handle_register(client_t *user_list, Packet *packet, int next_id);
void handle_login(client_t *user_list, Packet *packet, client_t *client);

int addOnlineUser(OnlineUser *onlineUsers, int onlineUserCount, int socket, const char* username);
int removeOnlineUser(OnlineUser *onlineUsers, int onlineUserCount, int socket);
void view_online_users(OnlineUser *onlineUsers, int onlineUserCount, client_t *client);
char* online_users(OnlineUser *onlineUsers, int onlineUserCount, client_t *client);
void add_room_to_user(client_t *client, client_t *user_list, const char *room_name, int type);
void remove_room_from_user(client_t *client, const char *room_name);

#endif // USER_H