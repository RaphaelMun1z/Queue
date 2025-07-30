typedef struct No {
    int item;
    struct No* next;
} No;

typedef struct Queue {
    No* begin;
    No* end;
} Queue;

Queue* initialize_queue();
int queue_exists(Queue *queue);
int queue_is_empty(Queue *queue);
int insert_item(Queue *queue, int item);
int remove_item(Queue *queue);
void select_item(Queue *queue, int position);
int get_queue_size(Queue *queue);
void print_queue(Queue *queue);