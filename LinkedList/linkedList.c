#include "LinkedList.h"

int main() {
   struct node *list = NULL;
   list = createList(list);
   list = addToBeginningOfList(list, 20);
   printf("%p\n", searchList(list, 20));

   return(0);
}

struct node *createList() {
   struct node *first = NULL;
   struct node *newNode;       // Temporary New Node
   newNode        = malloc(sizeof(struct node));
   newNode->value = 10;
   newNode->next  = first;     // Next is equal to NULL. So setting the first to NULL indicates that this list item is the first.
   first          = newNode;   // Since it is the first node we can assign the newely created node to the first.

   return(first);
}

struct node *addToBeginningOfList(struct node *list, int n) {
   struct node *newNode;
   newNode = malloc(sizeof(struct node));

   if (newNode == NULL) {
      printf("Error: malloc failed in add_to_list\n");
      exit(EXIT_FAILURE);
   }

   newNode->value = n;
   newNode->next  = list;
   return(newNode);
}

struct node *searchList(struct node *list, int n) {
   while (list != NULL && list->value != n) {
      list = list->next;
   }
   return(list);
}
