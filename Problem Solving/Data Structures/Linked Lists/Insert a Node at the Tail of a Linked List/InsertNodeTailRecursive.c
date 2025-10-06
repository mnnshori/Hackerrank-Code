// linked list recursive

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* listHead;
};

struct Node* createNode(int data);
struct LinkedList* createLinkedList();
void printList(struct Node* traverse);
void insertNodeTail(struct LinkedList* myList, int data);
void recursiveInsert(struct Node* traverse, int data);

int main() {
    struct LinkedList* myList = createLinkedList();
    int n;
    printf("input n: ");
    scanf("%d", &n);    

    printf("input %d numbers: ", n);
    for(int i=0; i<n; i++) {
        int temp;
        scanf("%d", &temp);

        insertNodeTail(myList, temp);
    }
    printList((*myList).listHead);
    return 0;
}

struct Node* createNode(int data) {
    struct Node* myNode = (struct Node*)realloc(NULL, 1 * sizeof(struct Node));
    (*myNode).data = data;
    (*myNode).next = NULL;
    return myNode;
}

struct LinkedList* createLinkedList() {
    struct LinkedList* myList = (struct LinkedList*)realloc(NULL, 1 * sizeof(struct LinkedList));
    (*myList).listHead = NULL;
    return myList;
}

void printList(struct Node* traverse) {
    if(traverse == NULL) {
        printf("NULL\n");
        return;
    } 
    
    printf("%d->", (*traverse).data);
    printList((*traverse).next); 
}

void insertNodeTail(struct LinkedList* myList, int data) {
    

    if((*myList).listHead == NULL) {
        struct Node* tempNode = createNode(data);
        (*myList).listHead = tempNode;
        
        return;
    } else {
        recursiveInsert((*myList).listHead, data);
    }
}

void recursiveInsert(struct Node* traverse, int data) {
    if( (*traverse).next == NULL ) {
        struct Node* tempNode = createNode(data);
        (*traverse).next = tempNode;
        return;
    }
    recursiveInsert((*traverse).next, data);
}