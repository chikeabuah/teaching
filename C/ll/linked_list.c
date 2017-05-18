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
} NODE;

void init(NODE** head) {
    *head = NULL;
}

void print_list(NODE* head) {
    NODE * temp;
    for (temp = head; temp; temp = temp->next)
        printf("%5d", temp->data.info);
}

NODE* add(NODE* node, DATA data) {
    NODE* temp = (NODE*) malloc(sizeof (NODE));
    if (temp == NULL) {
        exit(0); // no memory available
    }
    temp->data = data;
    temp->next = node;
    node = temp;
    return node;
}

void add_at(NODE* node, DATA data) {
    NODE* temp = (NODE*) malloc(sizeof (NODE));
    if (temp == NULL) {
        exit(EXIT_FAILURE); // no memory available
    }
    temp->data = data;
    temp->next = node->next;
    node->next = temp;
}

void remove_node(NODE* head) {
    NODE* temp = (NODE*) malloc(sizeof (NODE));
    if (temp == NULL) {
        exit(EXIT_FAILURE); // no memory available
    }
    temp = head->next;
    head->next = head->next->next;
    free(temp);
}

NODE * reverse_rec(NODE * ptr, NODE * previous) {
    NODE * temp;
    if (ptr->next == NULL) {
        ptr->next = previous;
        return ptr;
    } else {
        temp = reverse_rec(ptr->next, ptr);
        ptr->next = previous;
        return temp;
    }
}

NODE * reverse(NODE * node) {
    NODE * temp;
    NODE * previous = NULL;
    while (node != NULL) {
        temp = node->next;
        node->next = previous;
        previous = node;
        node = temp;
    }
    return previous;
}

NODE *free_list(NODE *head) {
    NODE *tmpPtr = head;
    NODE *followPtr;
    while (tmpPtr != NULL) {
        followPtr = tmpPtr;
        tmpPtr = tmpPtr->next;
        free(followPtr);
    }
    return NULL;
}

NODE *sort_list(NODE *head) {
    NODE *tmpPtr = head, *tmpNxt = head->next;
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

int main() {
    int i;
    NODE* head;
    NODE* node;
    DATA element;
    printf("Add Elements to List:\n");
    init(&head);
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
    element.info = 2000;
    add_at(node, element);
    head = reverse(head); // Revers The List
    head = sort_list(head); // Sort The List
    head = free_list(head);
    return (EXIT_SUCCESS);
}