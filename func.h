struct list{
	int x;
	struct list *next;
};

typedef struct list Node;

extern void printList(Node *head);
extern void deallocMem(Node* head, Node *tmp);
extern Node* insertAtHead(Node *head, int data);
extern void insertAtMiddle(Node *head, int pos, int idx, int data);
extern void insertAtEnd(Node *head, int data);
extern void update(Node *head, int position, int index, int data);
extern void deleteAtMiddle(Node *head, int position, int index);
extern void deleteEnd(Node *head);
extern Node* reverseList(Node *first, Node *rest, Node *last);