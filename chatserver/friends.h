#ifndef FRIENDS_H
#define FRIENDS_H

#include <pthread.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

#define MAX_FRIENDS 100
#define MAX_REQUESTS 100

typedef struct friend_list {
    int userid; // ID của người dùng
    int friends[MAX_FRIENDS]; // Danh sách bạn bè (ID)
    int friend_count; // Số lượng bạn bè
    int add_friend_requests[MAX_REQUESTS]; // Yêu cầu kết bạn (ID)
    int request_count; // Số lượng yêu cầu kết bạn
} friend_list_t;

friend_list_t * get_friend_list_by_userid(int userid);
int add_friend(int user_id, int friend_id);
int remove_friend(int user_id, int friend_id);
void create_friend_list(int userid);
void delete_friend_list(int userid);
void save_friend_lists(const char * filename);
void load_friend_lists(const char * filename);
void view_friend_list(client_t * user_list, client_t * client, OnlineUser * onlineUsers, int onlineUserCount);
void view_friend_online(client_t * user_list, client_t * client, OnlineUser * onlineUsers, int onlineUserCount);
int send_friend_request(int sender_id, int receiver_id);
int accept_friend_request(int sender_id, int receiver_id);
int decline_friend_request(int receiver_id, int sender_id);
void view_friend_requests(client_t * user_list, client_t * client);

extern friend_list_t friend_lists[MAX_CLIENTS];
extern int friend_list_count;

#endif // FRIENDS_H