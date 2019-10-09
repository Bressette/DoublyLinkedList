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

     if(temp == NULL)
     {
         newNode->prev = NULL;
         temp = newNode;
         return temp;
     }

     while(temp->next != NULL)
     {
         temp = temp->next;
     }
     temp->next = newNode;
     newNode->prev = temp;
     return head;

 }

 void printList(struct node *head)
 {
     struct node *temp = head;

     if(head == NULL)
     {
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

 int get(struct node *head, int position)
 {
     struct node *temp = head;

     for(int i = 0; i < position; i++)
     {
         temp = temp->next;
     }

     return temp->element;
 }

 int sizeList(struct node *head)
 {
     struct node *temp = head;
     int sizeOfList = 0;
     while(temp != NULL)
     {
         sizeOfList++;
         temp = temp->next;
     }
     return sizeOfList;
 }

int main()
{
    struct node *head = NULL;
    int element;
    head = insertLast(head, 10);
    head = insertLast(head, 20);
    head = insertLast(head, 30);
    head = insertLast(head, 40);
    head = insertLast(head, 50);
    element = get(head, 3);
    printf("The value at index 3 is %d\n", element);

    printList(head);
    int size = sizeList(head);
    printf("The size of the list is %d\n", size);
    return 0;
}
