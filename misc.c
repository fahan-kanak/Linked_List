#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void printList(Node *head) {
	if (head->next == NULL) {
		printf("%d\n",head->x);
		return;
	}
	printf("%d->",head->x);
	printList(head->next);
}

void deallocMem(Node* head, Node *tmp) {
	tmp->next = head->next;
	if (head->next == NULL) {
		free(head);
		free(tmp);
		return;
	}
	free(head);
	deallocMem(tmp->next, (Node*)malloc(sizeof(Node)));
}

void update(Node *head, int position, int index, int data) {
	if (index == 0) head->x = data;
	else if (index == -1) {
		if (head->next == NULL) {
			head->x = data;
			return;
		}
		update(head->next, position, index, data);
	} else {
		if (position == index) {
			head->x = data;
			return;
		}
		update(head->next, position + 1, index, data);
	}
}

Node* reverseList(Node* first, Node* rest, Node* last) {
	if (rest->next == NULL) {
		rest->next = first;
		last = rest;
		first->next = NULL;
		return last;
	}
	last = reverseList(first->next, rest->next, last);
	rest->next = first;
	first->next = NULL;
	return last;
}
