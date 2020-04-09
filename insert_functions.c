#include <stdlib.h>
#include "func.h"

Node* insertAtHead(Node *head, int data) {
	Node *tmp;
	tmp = (Node *)malloc(sizeof(Node));
	tmp->x = data;
	tmp->next = head;
	return tmp;
}

void insertAtMiddle(Node *head, int pos, int idx, int data) {
	if (pos == idx - 1) {
		Node *tmp;
		tmp = (Node *)malloc(sizeof(Node));
		tmp->x = data;
		tmp->next = head->next;
		head->next = tmp;
		return;
	}
	insertAtMiddle(head->next, pos + 1, idx, data);
}

void insertAtEnd(Node *head, int data) {
	if (head->next == NULL) {
		head->next = (Node*)malloc(sizeof(Node));
		head->next->x = data;
		head->next->next = NULL;
		return;
	}
	insertAtEnd(head->next, data);
}