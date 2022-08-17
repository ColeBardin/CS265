#include <stddef.h>
#include <stdlib.h> 
#include <stdio.h>

#define LIST_LEN 10

typedef struct sNode sNode ;

struct sNode
{
   int data ;
   sNode* next ;
};

void list_add( sNode **head, sNode *item){
	/* Make ITEM point to what head was pointing to */
	item->next=*head;

	/* Point HEAD to ITEM */
	*head = item;
}

/* listLength function:
Counts number of elements for list
Returns item count as size_t
Can handle 0 element lists (head being NULL)
Parameters:
	const sNode *L: 	sNode typedef pointer to head of list */
size_t listLength( const sNode *L ){
	size_t n;
	sNode *temp;
	if ( L == NULL) {
		/* No items if head of list is NULL */
		return 0;
		/* Must return here if NULL to avoid segfault when trying to access next member */
	} 
	/* At least one item */
	n=1;
	/* To avoid conflicts with const qualifier, assign temp to second element */
	temp=L->next;
	/* Iterate through each item in the list until hitting NULL (Tail) */
	for (; temp; temp = temp->next ){
		/* Increment counter for each element that isn't NULL */
		n++;
	}
	return n;
}

sNode* listRev( sNode *L ){
	sNode *prev=NULL;
	sNode *curr=L;
	sNode *next;

	for (; next;){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr=next;
	}
	return prev;
}

int main() {
	sNode *head = NULL;
	sNode *item;
	
	for (int i=0; i<LIST_LEN; i++) {
		item = malloc(sizeof(*item));
		item->data = i;
		list_add(&head, item);
	}

	printf("List:\n");
	for (item = head; item; item = item->next) {
		printf("%d\n", item->data);
	}
	printf("List has %zu item\n", listLength(head));

	printf("Reversed list:\n");
	head = listRev(head);
	for (item = head; item; item = item->next) {
		printf("%d\n", item->data);
	}
	return 0;
}
