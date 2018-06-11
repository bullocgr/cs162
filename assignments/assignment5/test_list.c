#include "list.h"
#include <stdio.h>
#include <stdlib.h>


int main () {
	char ans[2];
	int num;
	struct node *head = NULL;
	// do {
	do {
		printf("Enter a number: ");
		scanf("%d", &num);
		head = push(head, num);//Can change to append
		printf("Do you want another num (y or n): ");
		scanf("%1s", ans);
		// head = append(head, num);
		print(head, length(head));
	} while (ans[0] == 'y');
		// printf("Sort ascending or descending (a or d)? ");
		// scanf("%1s", ans);
		// if (ans[0] == 'a')
		// 	head = sort_ascending(head);
	// 	else if (ans[0] == 'd')
	// 		head = sort_descending(head);
	// 	print(head, length(head));
	// 	printf("Do you want to do this again (y or n)? ");
	// 	scanf("%1s", ans);
	// head = clear(head);
	// } while (ans[0] == 'y');
	// return 0;
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
	int i;
	for (i = 0; i < length; i++) {
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
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
	while(head->next != NULL) {
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
		free(head);
		next = head->next;
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
	if(head == NULL) return head;
	if(head->val == num) {
		head = head->next;
		return head;
	}
	struct node* temp = head;
	while (head->next != NULL) {
		if(head->next->val == num) {
			head->next = head->next->next;
		}
		head = head->next;
	}
	return head;
}

/*Function: sort ascending
Description: this will sort in ascending order
Parameters: pass in the list and sort the stuff
*/

struct node* sort_ascending(struct node* head) {
	int swapped;
	int temp;
	struct node* previous;
	// struct node* last = NULL;
	do {
		swapped = 0;
		// last = head;

		while (head->next != NULL) {
			printf("HELLOEOEOEOEO\n");
			if (previous->val > previous->next->val) {
				temp = head->next->val;
				head->next->val = head->val;
				head->val = temp;
				swapped = 1;
			}
			previous = previous->next;
		}
		head = previous;
	} while (swapped);
	return head;
}