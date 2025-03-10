#ifndef CHAT11_H
#define CHAT11_H

#include <pthread.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <time.h>
#include <unistd.h>
#include "user.h"
#include <dirent.h>

#define CONVERSATION_ID_LENGTH 12
#define MAX_MESSAGE_LENGTH 512
#define MAX_11_MESSAGES 1000
#define BUFFER_SIZE 1024
#define RESPONSE_SIZE (BUFFER_SIZE * MAX_11_MESSAGES + 1)


typedef struct {
    char timestamp[20];
    char username[BUFFER_SIZE];
    char message[MAX_MESSAGE_LENGTH];
} Message;

typedef struct {
    Message messages[MAX_11_MESSAGES];
    int count;
} MessageList;

void generate_fixed_id(char *buffer);
void ensure_directory_exists(const char *path);
char *get_or_create_shared_conversation_id(const char *sender_file, const char *receiver_file, char *buffer);
void request_private_message(client_t *user_list, client_t *sender, client_t *receiver);
void check_chat_partnership(client_t *sender, client_t *receiver);
void accept_chat_request(client_t *sender, client_t *receiver);
void decline_chat_request(client_t *sender, client_t *receiver);
void disconnect_chat(client_t *sender, client_t *receiver);
void send_private_message(client_t *sender, client_t *receiver, const char *message);
void store_message(char *senderName, char *receiverName, const char *message);
void retrieve_message(int sockfd, char *senderName, char *receiverName);
void log_message(const char *format, ...);



#endif // CHAT11_H