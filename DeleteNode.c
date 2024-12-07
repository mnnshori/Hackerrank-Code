#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
};

struct LinkedList* createLinkedList(void);
struct Node* createNode(int data);
void insertNodeAtEnd(struct LinkedList* myLinkedList, int data);
void printLinkedList(struct LinkedList* myLinkedList);
void deleteNode(struct LinkedList* myLinkedList, int position);

int main() {
    int n;
    int position;
    struct LinkedList* myLinkedList = createLinkedList();

    printf("input n: ");
    scanf("%d", &n);

    printf("input linked list: ");
    for(int i=0; i<n; i++) {
        int temp;
        scanf("%d", &temp);
        insertNodeAtEnd(myLinkedList, temp);
    }
    printLinkedList(myLinkedList);

    printf("input position: ");
    scanf("%d", &position);

    deleteNode(myLinkedList, position);
    printLinkedList(myLinkedList);
    
    return 0;
}

struct LinkedList* createLinkedList(void) {
    struct LinkedList* tempLinkedList = (struct LinkedList*)realloc(NULL, 1 * sizeof(struct LinkedList));
    (*tempLinkedList).head = NULL;
    return tempLinkedList;
}

struct Node* createNode(int data) {
    struct Node* tempNode = (struct Node*)realloc(NULL, 1 * sizeof(struct Node));
    (*tempNode).data = data;
    (*tempNode).next = NULL;
    return tempNode;
}

void insertNodeAtEnd(struct LinkedList* myLinkedList, int data) {
    struct Node* traverse = (*myLinkedList).head;
    struct Node* tempNode = createNode(data);

    if((*myLinkedList).head == NULL) {
        (*myLinkedList).head = tempNode;
        return;
    }

    while((*traverse).next != NULL) {
        traverse = (*traverse).next;
    }
    (*traverse).next = tempNode;
    return;
}

void printLinkedList(struct LinkedList* myLinkedList) {
    printf("\nprinting Linked List...\n");
    
    if((*myLinkedList).head == NULL) {
        printf("Error: Linked List is empty.\n");
        return;
    } else {
        struct Node* traverse = (*myLinkedList).head;
        while(traverse != NULL) {
            printf("%d ", (*traverse).data);
            traverse = (*traverse).next;
        }
        printf("\n");
    }
    return;
}

void deleteNode(struct LinkedList* myLinkedList, int position) {
    if((*myLinkedList).head == NULL) {
        printf("reached flag =0\n");
        printf("Error: LinkedList Underflow!");
        return;
    } else if(myLinkedList->head->next == NULL) {
        // why this code never gets executed?

        printf("reached flag =1\n");
        free(myLinkedList->head);
        return;
    } else {
        printf("reached flag =2\n");

        if(position == 0) {
            printf("deleting %d...\n", myLinkedList->head->data);
            struct Node* oldHead = myLinkedList->head;
            myLinkedList->head = myLinkedList->head->next;
            free(oldHead);
            return;
        } else {
            int positionCount = 0;
            struct Node* traverse = (*myLinkedList).head;
            while(positionCount != position -1) {
                ++positionCount;
                traverse = (*traverse).next;
            }
            
            struct Node* oldHead = (*traverse).next;
            printf("deleting %d...\n", oldHead->data);

            (*traverse).next = traverse->next->next;
            free(oldHead);
        }
        return;
    }
    return;
}