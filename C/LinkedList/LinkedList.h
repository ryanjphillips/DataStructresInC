#include <stdlib.h>
#include <stdio.h>

struct node {
	int value;
	struct node *next;
};

int main();
struct node *createList();
struct node *addToBeginningOfList(struct node *list, int n);
struct node *searchList(struct node *list, int n); 
struct node *deleteFromList(struct node *list, int n); 
