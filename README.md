# doublyLinkedList

Implementation of a doublyLinkedList using C and structs.

Doubly Linked List is defined by the struct

struct node
{
    int element;
    struct node *next;
    struct node *prev;
};

Functions:

 - get(struct node *head, int position) returns an element at a given index
 - printList(struct node *head) prints the given list, capable of printing from
both the head and the tail of the list.
 - removeElement(struct node *head, int position) removes an element at a given index
 and returns the head of the updated list.
 - insertLast(struct node *head, int newElement) inserts a new element at the end
 of the list and returns the head of the updated list
 - sizeList(struct node *head) returns the size of the given list
 - reverseList(struct node *head) reverses the given list recursively.
