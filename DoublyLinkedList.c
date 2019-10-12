#include "stdlib.h"
#include "stdio.h"

struct node
{
    int element;
    struct node *next;
    struct node *prev;
};

/*Function that takes in the tail of a list and an int element
 *and adds a newNode after tail and returns the new tail of the list
 */
 struct node *insertLast(struct node *tail, int newElement)
 {

     //initializes a new node and sets the value in new node to the new element
     struct node *newNode = malloc(sizeof(struct node));
     newNode->element = newElement;
     newNode->next = NULL;

     //case when the list is empty the tail becomes the newNode
     if(tail == NULL)
     {
         newNode->prev = NULL;
         return newNode;
     }

     //case when the list is not empty the element after tail becomes newNode
     tail->next = newNode;
     newNode->prev = tail;
     return newNode;

 }

 /*Function that can print a list given either the head or the tail of the list
  *if the head is given the list is printed in normal order; if the tail is given
  *the list is printed in reverse order
  */
 void printList(struct node *pointer)
 {
     struct node *temp = pointer;

     //case when the given list is empty
     if(pointer == NULL)
     {
         printf("The list is empty\n");
         return;
     }

     //case when the input is the head of the list
     else if(pointer->prev == NULL)
     {

         while(temp != NULL)
         {
             printf("%d ", temp->element);
             temp = temp->next;
         }
         printf("\n");
     }
     //case when the input is the tail of the list

     else if(pointer->next == NULL)
     {

         while(temp != NULL)
         {
             printf("%d ", temp->element);
             temp = temp->prev;
         }
         printf("\n");
     }

     //case when neither the head or the tail is passed into the function
     else
         printf("Neither the head or the tail was passed into the function\n");


 }

 /*Function that returns the value at a certain position in the list
  *and can take in either the head or the tail of the list to return
  *the element at a certain index
  */
 int get(struct node *pointer, int position)
 {
     struct node *temp = pointer;

     //case when the given pointer is the head of the list
     if(pointer->prev == NULL)
     {


        for(int i = 0; i < position; i++)
        {
            temp = temp->next;
        }
     }

     //case when the given pointer is the tail of the list
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

 /*Function that returns the size of the list as an int value.
  *The function can take either the head or the tail of the list
  *and iterate through the list to increment a counter that is returned
  *to give the size of the list
  */
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


 /*This function removes an element from the list given the head,
  *iterating through the list until temp = the element to be removed
  *NOTE: If the position specified is the tail of the list the tail
  *will not be updated and as a result the element in tail will be null
  *as temp is freed at the end of this function
  */
 struct node *removeElement(struct node *head, int position)
 {
     struct node *temp = head;
     struct node *temp2 = head;


     for(int i = 0; i < position; i++)
     {
         temp = temp->next;
     }

     //case when the position is the last index in the array
     if(position == (sizeList(head)-1))
     {
         //temp2 is the new tail of the list
         temp2 = temp->prev;
         temp2->next = NULL;
     }

     //case when the position is not the last index in the array
     else
     {
        temp2 = temp->prev;
        temp2->next = temp->next;
        temp2 = temp->next;
        temp2->prev = temp->prev;
     }
     free(temp);
     return head;

 }

/*Function that takes in the head of a list and recursively
 *reverses the elements in the list then returns the head of the list
 *Note that the tail is not updated in this function and will still
 *refer to the tail of the original list and will need to be updated
 *manually after this function is called
 */
struct node *reverseList(struct node *head)
{
    //base case
    if(head == NULL)
        return NULL;

    struct node *temp = head->next;
    head->next = head->prev;
    head->prev = temp;

    //case when the list is reversed and the new head is returned
    if(head->prev == NULL)
    {
       return head;
    }

    //recursive function call
    return reverseList(head->prev);

}



int main()
{
    //initializing variables
    struct node *head = NULL;
    struct node *tail = NULL;
    int element;
    int size;


    printf("Inserting elements\n");
    tail = insertLast(tail, 10);
    head = tail;
    tail = insertLast(tail, 20);
    tail = insertLast(tail, 30);
    tail = insertLast(tail, 40);
    tail = insertLast(tail, 50);

    printf("Printing from head\n");
    printList(head);
    printf("Printing from tail\n");
    printList(tail);
    printf("\n");

    printf("Get function for index 3 from the head\n");
    element = get(head, 3);
    printf("The value at index 3 is %d\n", element);
    printf("Get function for index 3 from the tail\n");
    element = get(tail, 3);
    printf("The value at index 3 is %d\n", element);
    printf("Get function for index 1 from the tail\n");
    element = get(tail, 1);
    printf("The value at index 1 is %d\n", element);

    printf("\n");
    printf("Printing from head\n");
    printList(head);

    printf("Printing from tail\n");
    printList(tail);

    printf("\n");

    printf("Finding the size of the list from the head\n");
    size = sizeList(head);
    printf("The size of the list is %d\n", size);

    printf("Finding the size of the list from the tail\n");
    size = sizeList(tail);
    printf("The size of the list is %d\n", size);

    printf("\n");

    /*Note that if the position that is specified in the removeElement
     *function is the tail of the list the value of tail will be null
     *as the tail element was the element that is removed and head is returned
     *from the function meaning that tail is not updated and will not function
     *properly unless manually reassigned to the correct tail value in the main function
     */
    printf("Removing the element in the 3rd index\n");
    head = removeElement(head, 3);

    printf("Printing from the head\n");
    printList(head);
    printf("Printing from the tail\n");
    printList(tail);

    printf("\n");
    printf("Removing the element in the 2nd index\n");
    head = removeElement(head, 2);

    printf("Printing from the head\n");
    printList(head);
    printf("Printing from the tail\n");
    printList(tail);
    printf("\n");

    printf("Inserting elements\n");
    tail = insertLast(tail, 42);
    tail = insertLast(tail, 90);

    printf("Printing from the head\n");
    printList(head);
    printf("Printing from the tail\n");
    printList(tail);

    printf("\n");

    printf("Reverse List\n");

    printf("Printing from the head before reversing the list\n");
    printList(head);

    /*Note that this function only changes the value of head
     *in the main function and as a result tail will not be updated
     *and will show the tail of the old list unless the tail is reassigned
     *based on the new head after the reverseList function
     */
    head = reverseList(head);

    printf("Printing from the head after reversing the list\n");
    printList(head);



    return 0;
}
