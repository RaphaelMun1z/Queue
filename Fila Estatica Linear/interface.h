#define N 3

typedef struct Queue {
    int data[N];
    int end;
} Queue;

void initialize_queue(Queue *queue);
int queue_is_empty(Queue *queue);
int queue_is_full(Queue *queue);
int insert_item(Queue *queue, int item);
int remove_item(Queue *queue);
void select_item(Queue *queue, int item);
int get_queue_size(Queue *queue);
void print_queue(Queue *queue);