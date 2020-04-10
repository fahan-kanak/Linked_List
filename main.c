/* 
 * File:   main.c
 * Author: farhan
 *
 * Created on April 7, 2020, 6:44 AM
 */

//Singly linked list entire project done 

#include <stdio.h>
#include <stdlib.h>
#include "func.h"

#define MENU printf("\nPress 1 to insert at head\nPress 2 to insert at middle\nPress 3 to insert at end\nPress 4 to delete the head\nPress 5 to delete at middle\nPress 6 to delete end node\nPress 7 to update\nPress 8 to print\nPress 9 to reverse list\nPress any other button to exit\n");
#define CHOICE printf("\nEnter Choice: ");
#define VALUE printf("\nEnter value: ");

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
		case 9:
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
				printf("\nMiddle is undefined right now!!!\n");
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
				printf("\nMiddle is undefined right now!!! So, deleting the head!\n");
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
		case 9:
			if (head->next == NULL) goto loop;
			Node* temp;
			temp = NULL;
			head = reverseList(head, head->next, temp);
			goto loop;
		default:
			printf("Bye!!!");
			deallocMem(head, (Node *)malloc(sizeof(Node)));
			goto exit;
	}

	exit: return 0;
}
