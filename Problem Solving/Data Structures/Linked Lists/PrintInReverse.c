#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
};

struct Node* createNode(int data);
struct LinkedList* createLinkedList(void);
void insertNodeAtEnd(struct LinkedList* myLinkedList, int data);
void printLinkedList(struct LinkedList* myLinkedList);
void printReverse(struct Node* traverse, int iterationCount);

int main() {
    int n;
    int iterationCount;
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
    
    printf("printing reverse...\n");

    iterationCount = 0;
    printReverse(myLinkedList->head, iterationCount);
    printf("\n");

    return 0;
}

struct Node* createNode(int data) {
    struct Node* tempNode = (struct Node*)realloc(NULL, 1 * sizeof(struct Node));
    if(tempNode == NULL) {
        printf("Error: Memory allocation failed");
        exit(1);
    }
    (*tempNode).data = data;
    (*tempNode).next = NULL;
    return tempNode;
}

struct LinkedList* createLinkedList(void) {
    struct LinkedList* tempLinkedList = (struct LinkedList*)realloc(NULL, 1 * sizeof(struct LinkedList));
    if(tempLinkedList == NULL) {
        printf("Error: Memory allocation failed");
        exit(1);
    }
    (*tempLinkedList).head = NULL;
    return tempLinkedList;
}

void insertNodeAtEnd(struct LinkedList* myLinkedList, int data) {
    struct Node* tempNode = createNode(data);
    //printf("compiler reached flag 2\n");
    //printf("head = %p\n", (*myLinkedList).head);
    if((*myLinkedList).head == NULL) {      
        //printf("compiler reached flag 0\n");  
        (*myLinkedList).head = tempNode;
        //printf("compiler reached flag 1\n");
        return;
    } else {
        struct Node* traverse = (*myLinkedList).head;
        while((*traverse).next != NULL) {
            traverse = (*traverse).next;
        }
        (*traverse).next = tempNode;
        return;
    }
    return;
}

void printLinkedList(struct LinkedList* myLinkedList) {
    printf("printing linked list...\n");
    struct Node* traverse = (*myLinkedList).head;
    while(traverse != NULL) {
        printf("%d ", (*traverse).data);
        traverse = (*traverse).next;
    }
    printf("\n");
    return;
}

void printReverse(struct Node* traverse, int iterationCount) {

    printf("entered iteration %d of the function\n", iterationCount);
    ++iterationCount;
    if(traverse == NULL) {
        printf("traverse == NULL\n");
        printf("exiting...\n");
        return;
    }
    printReverse(traverse->next, iterationCount);

    printf("rolling back from iteration %d...\n", iterationCount);
    printf("printing traverse->data...\n");
    printf("%d\n", traverse->data);
    return;
}
