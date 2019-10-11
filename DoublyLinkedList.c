#include "stdlib.h"
#include "stdio.h"

struct node
{
    int element;
    struct node *next;
    struct node *prev;
};

 struct node *insertLast(struct node *head, int newElement, struct node **tail)
 {
     struct node *temp = (*tail);
     struct node *newNode = malloc(sizeof(struct node));
     newNode->element = newElement;
     newNode->next = NULL;

     if(temp == NULL)
     {
         newNode->prev = NULL;
         temp = newNode;
         (*tail) = temp;
         return temp;
     }

     temp->next = newNode;
     newNode->prev = temp;
     (*tail) = newNode;
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

 int get(struct node *pointer, int position)
 {
     struct node *temp = pointer;

     if(pointer->prev == NULL)
     {


     for(int i = 0; i < position; i++)
     {
         temp = temp->next;
     }
     }

     else
     {
         int iterations = sizeList(temp) - position;
         for(int i = 1; i < iterations; i++)
         {
             temp = temp->prev;
         }
     }

     return temp->element;
 }

 int sizeList(struct node *pointer)
 {
     struct node *temp = pointer;
     int sizeOfList = 0;

     if(temp->prev == NULL)
     {
        while(temp != NULL)
        {
            sizeOfList++;
            temp = temp->next;
        }
     }

     else
     {
         while(temp != NULL)
         {
             sizeOfList++;
             temp = temp->prev;
         }
     }
     return sizeOfList;
 }

 struct node *removeElement(struct node *head, int position, struct node **tail)
 {
     struct node *temp = head;
     struct node *temp2 = head;


     for(int i = 0; i < position; i++)
     {
         temp = temp->next;
     }

     if(position == (sizeList(head)-1))
     {
         temp2 = temp->prev;
         temp2->next = NULL;
         (*tail) = temp2;
     }

     else
     {
     temp2 = temp->prev;
     temp2->next = temp->next;
     temp2 = temp->next;
     temp2->prev = temp->prev;
     }

     return head;

 }


struct node *reverseList(struct node *head)
{
    if(head == NULL)
        return NULL;

    struct node *temp = head->next;
    head->next = head->prev;
    head->prev = temp;

    if(head->prev == NULL)
        return head;

    return reverseList(head->prev);

}



int main()
{
    struct node *head = NULL;
    struct node *tail = NULL;
    int element;

    head = insertLast(head, 10, &tail);
    head = insertLast(head, 20, &tail);
    head = insertLast(head, 30, &tail);
    head = insertLast(head, 40, &tail);
    head = insertLast(head, 50, &tail);

    element = get(head, 3);
    printf("The value at index 3 is %d\n", element);
    element = get(tail, 3);
    printf("The value at index 3 is %d\n", element);
    element = get(tail, 1);
    printf("The value at index 1 is %d\n", element);

    printf("Printing from head\n");
    printList(head);

    printf("Printing from tail\n");
    printList(tail);

    int size = sizeList(head);
    printf("The size of the list is %d\n", size);

    printf("\n");

    printf("Removing the element in the 4th index\n");
    removeElement(head, 4, &tail);

    printf("Printing from the head\n");
    printList(head);
    printf("Printing from the tail\n");
    printList(tail);

    printf("\n");
    printf("Removing the element in the 2nd index\n");
    removeElement(head, 2, &tail);

    printf("Printing from the head\n");
    printList(head);
    printf("Printing from the tail\n");
    printList(tail);
    printf("\n");

    printf("Inserting elements\n");
    insertLast(head, 42, &tail);
    insertLast(head, 90, &tail);

    printf("Printing from the head\n");
    printList(head);
    printf("Printing from the tail\n");
    printList(tail);

    printf("\n");

    printf("Reverse List\n");

    head = reverseList(head);

    printf("Printing from the head\n");
    printList(head);


    return 0;
}
