//https://gist.github.com/ArnonEilat/4470948 

/** 
http://www.learn-c.org/en/Linked_lists

Essentially, linked lists function as an array that can grow and shrink as needed, 
from any point in the array.

Linked lists have a few advantages over arrays:

Items can be added or removed from the middle of the list
There is no need to define an initial size
However, linked lists also have a few disadvantages:

There is no "random" access - it is impossible to reach the nth item in the array
without first iterating over all items up until that item.

This means we have to start from the beginning of the list and count how many times
we advance in the list until we get to the desired item.

Dynamic memory allocation and pointers are required, which complicates the code and 
increases the risk of memory leaks and segment faults.

Linked lists have a much larger overhead over arrays, since linked list items are dynamically
allocated (which is less efficient in memory usage) and each item in the list also must store an additional pointer.

**/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int info;
} DATA;

typedef struct node {
    DATA data;
    struct node* next;
} Node;

void init(Node** head, DATA data) {
    *head = (Node*)malloc(sizeof (Node));
    (*head)->data = data;
    (*head)->next = NULL;
}

void print_list(Node* head) {
    Node * temp;
    for (temp = head; temp; temp = temp->next)
        printf("%5d", temp->data.info);
}

Node* add(Node* node, DATA data) {
    Node* temp = (Node*) malloc(sizeof (Node));
    if (temp == NULL) {
        exit(0); // no memory available
    }
    temp->data = data;
    temp->next = node;
    return temp;
}

void remove_node(Node* head) {
    Node* temp = (Node*) malloc(sizeof (Node));
    if (temp == NULL) {
        exit(EXIT_FAILURE); // no memory available
    }
    // copy next node's info to given node
    // delete next node
    temp = head->next;
    head->data = head->next->data;
    head->next = head->next->next;
    free(temp);
}

Node * reverse(Node * node) {
    Node * temp;
    Node * previous = NULL;
    while (node != NULL) {
        temp = node->next;
        node->next = previous;
        previous = node;
        node = temp;
    }
    return previous;
}

Node *free_list(Node *head) {
    Node *tmpPtr = head;
    Node *followPtr;
    while (tmpPtr != NULL) {
        followPtr = tmpPtr;
        tmpPtr = tmpPtr->next;
        free(followPtr);
    }
    return NULL;
}

Node *sort_list(Node *head) {
    Node *tmpPtr = head, *tmpNxt = head->next;
    DATA tmp;
    while (tmpNxt != NULL) {
        while (tmpNxt != tmpPtr) {
            if (tmpNxt->data.info < tmpPtr->data.info) {
                tmp = tmpPtr->data;
                tmpPtr->data = tmpNxt->data;
                tmpNxt->data = tmp;
            }
            tmpPtr = tmpPtr->next;
        }
        tmpPtr = head;
        tmpNxt = tmpNxt->next;
    }
    return tmpPtr;
}

// merge a linked list into another at alternate positions
// check if a singly linked list is a palindrome
// remove duplicate elements from a sorted linked list

int main() {
    int i;
    Node* head;
    Node* node;
    DATA element;
    element.info = 52;
    printf("Add Elements to List:\n");
    init(&head, element);
    for (i = 53; i <= 63; i++) {
        element.info = i;
        printf("Add Element %2d To The List.\n", element.info);
        head = add(head, element);
    }
    printf("\nPrint The List:\n");
    print_list(head);
    printf("\nRemove Element From The List:\n");
    node = head->next->next;
    remove_node(node);
    printf("\nAdd Element To The List:\n");
    node = head->next->next->next;
    head = reverse(head); // Revers The List
    head = sort_list(head); // Sort The List
    head = free_list(head);
    return (EXIT_SUCCESS);
}