#define N 3

typedef struct Queue {
    int data[N];
    int size;
    int begin;
    int end;
} Queue;

void initialize_queue(Queue *queue);

int queue_is_empty(Queue *queue);
int queue_is_full(Queue *queue);
int queue_size(Queue *queue);

void insert_item(Queue *queue, int item);
int remove_item(Queue *queue);
int consult_first(Queue *queue);

void print_queue(Queue *queue);