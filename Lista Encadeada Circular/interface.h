#define N 3

typedef struct Node {
    int item;
    struct Node* next;
} Node;

typedef struct CircularList {
    Node* tail;
    int size;
} CircularList;

void initialize_list(CircularList *list);
int is_empty(CircularList *list);
void insert_at_begin(CircularList *list, int value);
void insert_at_end(CircularList *list, int value);
void print_list(CircularList *list);
int remove_item(CircularList *list, int value);
void destroy_list(CircularList *list);