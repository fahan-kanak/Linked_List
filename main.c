/* 
 * File:   main.c
 * Author: farhan
 *
 * Created on April 7, 2020, 6:44 AM
 */

#include <stdio.h>
#include <stdlib.h>

#define MENU printf("\nPress 1 to insert at head\nPress 2 to insert at middle\nPress 3 to insert at end\nPress 4 to delete the head\nPress 5 to delete at middle\nPress 6 to delete end node\nPress 7 to update\nPress 8 to print\nPress any other button to exit\n");
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

void deleteAtMiddle(Node *head, int position, int index) {
	if (position == index - 1) {
		Node *tmp;
		tmp = head->next;
		head->next = head->next->next;
		free(tmp);
		return;
	}
	deleteAtMiddle(head->next, position + 1, index);
}

void deleteEnd(Node *head) {
	if (head->next->next == NULL) {
		free(head->next);
		head->next = NULL;
		return;
	}
	deleteEnd(head->next);
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
		case 3:
			VALUE
			scanf("%d", &x);
			getchar();
			head = (Node *)malloc(sizeof(Node));
			head->x = x;
			head->next = NULL;
			goto loop;
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
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
			if (head->next == NULL) {
				printf("\nMiddle is undefined right now!!!");
				goto loop;
			}
			printf("\nEnter position: ");
			int index;
			scanf("%d", &index);
			getchar();
			VALUE
			scanf("%d", &x);
			getchar();
			insertAtMiddle(head, 0, index, x);
			goto loop;
		case 3:
			VALUE
			scanf("%d", &x);
			getchar();
			insertAtEnd(head, x);
			goto loop;
		case 4:
			if (head->next == NULL) {
				free(head);
				goto label;
			}
			Node *tmp;
			tmp = head;
			head = head->next;
			free(tmp);
			goto loop;
		case 5:
			if (head->next == NULL) {
				printf("\nMiddle is undefined right now!!! So, deleting the head!");
				free(head);
				goto label;
			}
			printf("Enter position: ");
			scanf("%d", &index);
			deleteAtMiddle(head, 0, index);
			goto loop;
		case 6:
			if (head->next == NULL) {
				free(head);
				goto label;
			}
			deleteEnd(head);
			goto loop;
		case 7:
			printf("\nEnter position (-1 to update the last data): ");
			scanf("%d", &index);
			VALUE
			scanf("%d", &x);
			update(head, 0, index, x);
			goto loop;
		case 8:
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