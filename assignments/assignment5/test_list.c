#include "list.h"
#include <stdio.h>
#include <stdlib.h>


int main () {
	char ans[2];
	int num;
	struct node *head = NULL;
	do {
		do {
			printf("Enter a number: ");
			scanf("%d", &num);
			head = push(head, num);//Can change to append
			printf("Do you want another num (y or n): ");
			scanf("%1s", ans);
		} while (ans[0] == 'y');
		printf("Sort ascending or descending (a or d)? ");
		scanf("%1s", ans);
		if (ans[0] == 'a')
			head = sort_ascending(head);
		else if (ans[0] == 'd')
			head = sort_descending(head);
		print(head, length(head));
		printf("Do you want to do this again (y or n)? ");
		scanf("%1s", ans);
		head = clear(head);
	} while (ans[0] == 'y');
	return 0;
}

/*Function: length
Description: this will count how long the list is and return that number
Parameters: read in the list and return the length
*/

int length(struct node* head) {
	int counter;
	while (head != NULL) {
		counter++;
		head = head->next;
	}

	return counter;
}

/*Function: print
Description: this will print the list
Parameters: this will read in the list and take the length
*/

void print(struct node* head, int length) {
	struct node* current = head;
	while (current != NULL) {
		printf("%d ", current->val);
		current = current->next;
	}
	putchar('\n');
}

/*Function: push
Description: this will take the first value inputted and make that the head
Parameters: read in the number and the length
*/

struct node* push(struct node* head, int num) {
	struct node* new_node = malloc(sizeof(struct node));
	new_node->val = num;
	new_node->next = head;
	head = new_node;
	return head;
}

/*Function: append
Description: this will put the number and put it in the back
Parameters: this takes in the head and the number and returns the head
*/

struct node* append(struct node* head, int num) {
	struct node* new_node = malloc(sizeof(struct node));
	new_node->val = num;
	while (head->next != NULL) {
		head = head->next;
	}
	head->next = new_node;
	return head;
}


/*Function: clear
Description: this will clear the linked list
Parameters: pass in the list and return the head which should be at null
*/

struct node* clear(struct node* head) {//this doesn't work
	struct node* next;
	while (head != NULL) {
		next = head->next;
		free(head);
		head = next;
	}
	head = NULL;
	return head;
}

/*Function: remove node
Description: this will remove a node from the linked list
Parameters: pass in the head and the length and return the head
*/

struct node* remove_node(struct node* head, int num) {
	if (head == NULL) return head;
	if (head->val == num) {
		head = head->next;
		return head;
	}
	struct node* temp = head;
	while (head->next != NULL) {
		if (head->next->val == num) {
			head->next = head->next->next;
		}
		head = head->next;
	}
	return head;
}

/*Function: swap
Description: this will swap the things
Parameters: pass in the two nodes you want to swap
*/

struct node* swap(struct node* previous, struct node* current) {
	previous->next = current->next;
	current->next = previous;
	return current;
}

/*Function: sort ascending
Description: this will sort in ascending order
Parameters: pass in the list and sort the stuff
*/

struct node* sort_ascending(struct node* head) {
	if (head ==  NULL)
		return head;
	struct node* previous;
	struct node* current;
	struct node* current1;
	int unsorted = 1;

	current1 = (struct node*)malloc(sizeof(struct node)); //create node in front of head in order to sort the head with the rest

	current1->next = head;
	if (head->next != NULL) {
		while (unsorted) {
			unsorted = 0;
			current = current1;
			previous = current1->next;
			while (previous->next != NULL) {
				if (previous->val > previous->next->val) {
					current1 = swap(previous, previous->next);
					unsorted = 1;
				}
				current = previous;
				if (previous->next)
					previous = previous->next;
			}
		}
	}
	previous = current1->next;
	free(current1);
	return previous;

}

/*Function: sorting descending
Description: this will sort the stuff in descending order
Parameters: this will pass in the head
*/

struct node* sort_descending(struct node* head) {
	if (head ==  NULL)
		return head;
	struct node* previous;
	struct node* current;
	struct node* current1;
	int unsorted = 1;

	current1 = (struct node *)malloc(sizeof(struct node)); //create node in front of head in order to sort the head with the rest

	current1->next = head;
	if (head->next != NULL) {
		while (unsorted) {
			unsorted = 0;
			current = current1;
			previous = current1->next;
			while (previous->next != NULL) {
				if (previous->val < previous->next->val) {
					current->next = swap(previous, previous->next);
					unsorted = 1;
				}
				current = previous;
				if (previous->next)
					previous = previous->next;
			}
		}
	}
	previous = current1->next;
	free(current1);
	return previous;

}

/*Function: insert middle
Description: this will allow the user to put a number in the middle of the list
Parameters: pass in the head, the value they want to input, and where they want to input it
*/

struct node* insert_middle(struct node* head, int num, int index) {
	int i;
	struct node* current = head;
	struct node* temp;
	struct node* new_node = malloc(sizeof(struct node));
	new_node->val = num;
	if(index == 0) {
		head = push(head, num);
	}
	for (i = 0; i < index - 1; i++) {
		if (i == index) {
			current = current->next;
		}
		temp = current->next;
		current->next = new_node;
		new_node->next = temp;
		return head;
	}
}