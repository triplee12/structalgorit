#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node {
	int data;
	int key;
	struct Node *next;
} node_t;

node_t *head = NULL;
node_t *current = NULL;

void printList()
{
	node_t *ptr = head;
	printf("\n[");

	/* start from the beginning of the node */
	while(ptr != NULL)
	{
		printf("(%d, %d), ", ptr->key, ptr->data);
		ptr = ptr->next;
	}

	printf("]\n");
}

/* Insert link at the first location */

void insertFirst(int key, int data)
{
	/* create link */
	node_t *link = malloc(sizeof(node_t));
	link->key = key;
	link->data = data;

	/* point it to the old first node */
	link->next = head;
	/* point the first to the new node */
	head = link;
}

/* delete first item */
node_t *deleteFirst()
{
	/* save reference to first link */
	node_t *tempLink = head;
	/* mark next to first link as first */
	head = head->next;

	/* return the deleted link */
	return (tempLink);
}

/* is the list empty */

bool isEmpty()
{
	return (head == NULL);
}

/* check the length of the list */
int length()
{
	int len = 0;
	node_t *current;

	for (current = head; current != NULL; current = current->next)
		len++;

	return (len);
}

/* find a link with given key */
node_t *find(int key)
{
	/* start from the first link */
	node_t *current = head;

	if (head == NULL)
		return (NULL);

	/* navigate/traverse through list */
	while (current->key != key)
	{
		/* if it is last node */
		if (current->next == NULL)
			return (NULL);
		else
			current = current->next; /* go to next link */
	}

	/* if data found return the current link */
	return (current);
}

/* delete a link with a given key */
node_t *delete(int key)
{
	/* start from the first link */
	node_t *current = head;
	node_t *previous = NULL;

	/* if list is empty */
	if (head == NULL)
		return (NULL);
	/* traverse through the list */
	while (current->key != key)
	{
		/* if it is last node */
		if (current->next == NULL)
			return (NULL);
		else
		{
			/* store reference to current link */
			previous = current;
			/* move to next link */
			current = current->next;
		}
	}

	/* found a match, update the link */
	if (current == head)
	{
		/* change first to point to next link */
		head = head->next;
	}
	else
	{
		/* bypass the current link */
		previous->next = current->next;
	}

	return (current);
}

void sort()
{
	int i, j, k, tempData, tempKey;
	node_t *current;
	node_t *next;

	int size = length();
	k = size;
	
	for (i = 0; i < size - 1; i++, k--)
	{
		current = head;
		next = head->next;

		for (j = 1; j < k; j++)
		{
			if (current->data > next->data)
			{
				tempData = current->data;
				current->data = next->data;
				next->data = tempData;
				tempKey = current->key;
				current->key = next->key;
				next->key = tempKey;
			}

			current = current->next;
			next = next->next;
		}
	}
}

void reverse(node_t **head_ref)
{
	node_t *prev = NULL;
	node_t *current = *head_ref;
	node_t *next;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}

int main()
{
	insertFirst(1, 10);
	insertFirst(2, 20);
	insertFirst(3, 30);
	insertFirst(4, 40);
	insertFirst(5, 50);
	insertFirst(6, 60);

	printf("----------------Original List-------------------\n");
	/* print list */
	printList();

	while (!isEmpty())
	{
		node_t *temp = deleteFirst();
		printf("\n------------------Deleted values----------------\n");
		printf("(%d, %d), ", temp->key, temp->data);
	}

	printf("\nList after deleting all items: \n");
	printList();
	insertFirst(1,10);
	insertFirst(2,20);
	insertFirst(3,30);
	insertFirst(4,40);
	insertFirst(5,50);
	insertFirst(6,60);
	printf("\n----------------REstored List------------------\n");
	printList();

	node_t *found = find(5);

	if (found != NULL)
	{
		printf("----------------Element Found---------------\n");
		printf("(%d, %d), \n", found->key, found->data);
	}
	else
		printf("Element not found.\n");
	delete(5);
	printf("List after deleting an item: \n");
	printList();

	found = find(5);
	if(found != NULL)
	{
		printf("----------------Element Found----------------\n");
		printf("(%d, %d), \n", found->key, found->data);
	}
	else
		printf("Element Not Found.\n");

	sort();
	printf("List after sorting the data\n");
	printList();
	reverse(&head);
	printf("\nList after reversing the data\n");
	printList();
}
