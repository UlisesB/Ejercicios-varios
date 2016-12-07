#include <stdio.h>
#include "lista_ligada.h"

int main (int argc, char *argv[])
{
	Node *list1 = NULL;
	Node *list2 = NULL;
	Node *list3 = NULL;
	
	Push (&list1, 1);
	Push (&list1, 9);
	Push (&list1, 4);
	
	Push (&list2, 2);
	Push (&list2, 0);

	
	printf("List 1: ");
	Print (list1);
	printf("List 2: ");
	Print (list2);
	list3 = NewList (list1, list2);
	printf("List 3: ");
	Print (list3);
	
	return 0;
}
