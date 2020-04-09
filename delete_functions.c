#include <stdlib.h>
#include "func.h"

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