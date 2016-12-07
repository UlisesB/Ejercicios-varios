#ifndef __LISTA_LIGADA_H__
#define __LISTA_LIGADA_H__

#include <stdlib.h>
#include <stdio.h>

struct _node{
	int digit;
	struct _node *next;
};
typedef struct _node Node;

void Push (Node **head, int digit) {
	Node *temp;
	Node *current;
	
	temp = (Node*) malloc (sizeof(Node));
	temp->digit = digit;
	temp->next = NULL;

	if (*head == NULL) {
		*head = temp;
	}
	else {
		current = *head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = temp;
	}
}

void Print (Node *head) {
	while (head != NULL) {
		printf ("%i", head->digit);
		head = head->next;
	}
	printf("\n");
}

Node *ReverseList (Node *current) {
	Node *head;
	if (current->next == NULL) {
		return current;
	}
	head = ReverseList (current->next);
	current->next->next = current;
	current->next = NULL;
	return head;
}

Node *NewList (Node *list1, Node *list2) {
	Node *temp1, *temp2;
	Node *last, *current;
	int carry = 0, number;
	
	temp1 = ReverseList (list1);
	temp2 = ReverseList (list2);
	last = NULL;
	
	while (temp1 != NULL && temp2 != NULL) {
		current = (Node*) malloc (sizeof(Node));
		number = temp1->digit + temp2->digit + carry;
		current->digit = number % 10;
		
		carry = number / 10;		
		current->next = last;
		last = current;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	while (temp1 != NULL) {
		current = (Node*) malloc (sizeof(Node));
		number = temp1->digit + carry;
		current->digit = number % 10;
			
		carry = number / 10;
		current->next = last;
		last = current;
		temp1 = temp1->next;
	}
	while (temp2 != NULL) {
		current = (Node*) malloc (sizeof(Node));
		number = temp2->digit + carry;
		current->digit = number % 10;
			
		carry = number / 10;
		current->next = last;
		last = current;
		temp2 = temp2->next;
	}
	return last;
}

#endif

