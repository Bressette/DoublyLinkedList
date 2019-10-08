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
     newNode->next = NULL;

     if(head == NULL)
     {
         head = newNode;
         return head;
     }

     while(temp->next != NULL)
     {
         temp = temp->next;
     }
     temp->next = newNode;
     newNode->prev = temp;
     return temp;

 }

 void printList(struct node *head)
 {
     struct node *temp = head;

     if(head == NULL)
     {
         printf("in else if");
         printf("in if");
         printf("The list is empty\n");
         return;
     }

     //case when the input is the head of the list
     else if(head->prev == NULL)
     {

         while(temp != NULL)
         {
             printf("%d ", temp->element);
             temp = temp->next;
         }
         printf("\n");
     }
     //case when the input is the tail of the list

     else if(head->next == NULL)
     {

         while(temp != NULL)
         {
             printf("%d ", temp->element);
             temp = temp->prev;
         }
         printf("\n");
     }

     else
        printf("Neither the head or the tail was passed into the function\n");

 }

int main()
{
    struct node *head = NULL;

    head = insertLast(head, 10);
    head->prev = NULL;
    head = insertLast(head, 20);
    printf("%d\n", head->element);

    printList(head);
    return 0;
}
