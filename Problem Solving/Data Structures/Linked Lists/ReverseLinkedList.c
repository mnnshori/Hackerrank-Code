#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

struct Node* createNode(int data);
struct LinkedList* createList(void);
void insertNodeAtEnd(struct LinkedList* myList, int data);
void printList(struct LinkedList* myList);
void reverseList(struct LinkedList* myList);

int main() {
    int testCases;
    int listLength;

    printf("input number of testCases: ");
    scanf("%d", &testCases);

    for(int i=0; i<testCases; i++) {

        struct LinkedList* myList = createList();
        printf("input linked list length: ");
        scanf("%d", &listLength);

        printf("input linked list elements: ");
        
        for(int i=0; i<listLength; i++) {
            int temp;
            scanf("%d", &temp);
            insertNodeAtEnd(myList, temp);
        }
        printList(myList);

        printf("reversing linked list...\n");
        reverseList(myList);
        printList(myList);
    }

    return 0;
}

struct Node* createNode(int data) {
    struct Node* tempNode = (struct Node*)realloc(NULL, 1 * sizeof(struct Node));
    (*tempNode).data = data;
    (*tempNode).next = NULL;
    return tempNode;
}

struct LinkedList* createList(void) {
    struct LinkedList* tempList = (struct LinkedList*)realloc(NULL, 1 * sizeof(struct LinkedList));
    (*tempList).head = NULL;
    return tempList;
}

void insertNodeAtEnd(struct LinkedList* myList, int data) {
    struct Node* tempNode = createNode(data);

    if((*myList).head == NULL) {
        (*myList).head = tempNode;
        return;
    } else {
        struct Node* traverse = (*myList).head;
        while((*traverse).next != NULL) {
            traverse = (*traverse).next;
        }
        (*traverse).next = tempNode;
        return;
    }
}

void printList(struct LinkedList* myList) {
    printf("printing linked list...\n");
    struct Node* traverse = (*myList).head;
    while(traverse != NULL) {
        printf("%d ", (*traverse).data);
        traverse = (*traverse).next;
    }
    printf("\n");
    return;
}

void reverseList(struct LinkedList* myList) {
    struct Node *current = (*myList).head;
    struct Node* prev = NULL;
    struct Node* next = NULL;

    if((*myList).head == NULL) {return;}
    if(myList->head->next == NULL) {return;}

    while(current != NULL) {
        next = current->next;
        current->next = prev;
        
        prev = current;
        current = next;
    }

    (*myList).head = prev;

    return;
}
