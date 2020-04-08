/* 
 * File:   main.c
 * Author: farhan
 *
 * Created on April 7, 2020, 6:44 AM
 */

#include <stdio.h>
#include <stdlib.h>

#define MENU printf("\nPress 1 to insert at head\nPress 2 to insert at end\nPress 3 to print\nPress any other button to exit\n");
#define CHOICE printf("\nEnter Choice: ");
#define VALUE printf("\nEnter value: ");

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

Node* insertAtHead(Node *head, int data) {
	Node *tmp;
	tmp = (Node *)malloc(sizeof(Node));
	tmp->x = data;
	tmp->next = head;
	return tmp;
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

int main(int argc, char** argv) {
	Node *head;
	int input, x;
	label: MENU
	CHOICE
	scanf("%d", &input);
	getchar();
	switch (input) {
		case 1:
		case 2:
			VALUE
			scanf("%d", &x);
			getchar();
			head = (Node *)malloc(sizeof(Node));
			head->x = x;
			head->next = NULL;
			goto loop;
		case 3:
			printf("List is empty!!!\n");
			goto label;
		default:
			printf("Bye!!!");
			goto exit;
	}
	loop: MENU
	CHOICE
	scanf("%d", &input);
	getchar();
	switch (input) {
		case 1:
			VALUE
			scanf("%d", &x);
			getchar();
			head = insertAtHead(head, x);
			goto loop;
		case 2:
			VALUE
			scanf("%d", &x);
			getchar();
			insertAtEnd(head, x);
			goto loop;
		case 3:
			printf("The list contains: ");
			printList(head);
			goto loop;
		default:
			printf("Bye!!!");
			deallocMem(head, (Node *)malloc(sizeof(Node)));
			goto exit;
	}

	exit: return 0;
}