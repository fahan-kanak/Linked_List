/* 
 * File:   main.c
 * Author: farhan
 *
 * Created on April 7, 2020, 6:44 AM
 */

#include <stdio.h>
#include <stdlib.h>

struct list{
	int x;
	struct list *next;
};

typedef struct list Node;

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

int main(int argc, char** argv) {
	Node *head, *second, *third;
	head = (Node*)malloc(sizeof(Node));
	head->x = 10;
	head->next = (Node*)malloc(sizeof(Node));
	second = head->next;
	second->x = 20;
	second->next = (Node*)malloc(sizeof(Node));
	third = second->next;
	third->x = 30;
	third->next = NULL;
	printList(head);
	deallocMem(head, (Node*)malloc(sizeof(Node)));

	return 0;
}