typedef struct Node {
    int item;
    struct Node* next;
} Node;

typedef struct SinglyLinkedList {
    Node* head; 
    Node* tail;
    int size;
} SinglyLinkedList;

void initialize_list(SinglyLinkedList *list);
int is_empty(SinglyLinkedList *list);
void insert_at_begin(SinglyLinkedList *list, int value);
void insert_at_end(SinglyLinkedList *list, int value);
void print_list(SinglyLinkedList *list);
int remove_item(SinglyLinkedList *list, int value);
void destroy_list(SinglyLinkedList *list);