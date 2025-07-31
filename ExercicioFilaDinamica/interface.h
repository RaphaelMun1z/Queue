typedef struct Message {
    char sender_name[100];
    char content[256];
} Message;

typedef struct No {
    Message msg;
    struct No* next;
} No;

typedef struct Queue {
    No* begin;
    No* end;
} Queue;

Queue* initialize_queue();
int queue_exists(Queue *queue);
int queue_is_empty(Queue *queue);
void send_message(Queue* queue, Message msg);
void view_messages(Queue* queue);
void consult_and_remove_first_message(Queue* queue);
void search_messages_by_sender(Queue* queue, char sender_name[100]);
int count_total_messages(Queue* queue);
void exit_and_free_memory(Queue* queue);