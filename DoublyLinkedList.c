#include "stdlib.h"
#include "stdio.h"

struct node
{
    int element;
    struct node *next;
    struct node *prev;
};

 struct node *insertLast(struct node *head, int newElement)
 {
     struct node *temp = head;
     struct node *newNode = malloc(sizeof(struct node));
     newNode->element = newElement;

     if(head == NULL)
     {
         printf("The list is empty\n");
         return;
     }

     while(temp->next != NULL)
     {
         temp = temp->next;
     }
     temp->next = newNode;
     newNode->prev = temp;
     return temp;

 }

int main()
{
    struct node *head = NULL;
    head = insertLast(head, 10);
    return 0;
}
