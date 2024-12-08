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

int main() {
    int n;
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

    return 0;
}

struct Node* createNode(int data) {
    struct Node* tempNode = (struct Node*)realloc(NULL, 1 * sizeof(struct Node));
    (*tempNode).data = data;
    (*tempNode).next = NULL;
    return tempNode;
}

struct LinkedList* createLinkedList(void) {
    struct LinkedList* tempLinkedList = (struct LinkedList*)realloc(NULL, 1 * sizeof(struct LinkedList));
    return tempLinkedList;
}

void insertNodeAtEnd(struct LinkedList* myLinkedList, int data) {
    struct Node* tempNode = createNode(data);
    if((*myLinkedList).head == NULL) {
        (*myLinkedList).head = tempNode;
        return;
    } else {
        struct Node* traverse = (*myLinkedList).head;
        while((*traverse).next != NULL) {
            traverse = (*traverse).next;
        }
        (*traverse).next = tempNode;
        return;
    }
}

void printLinkedList(struct LinkedList* myLinkedList) {
    printf("printing linked list...\n");
    struct Node* traverse = (*myLinkedList).head;
    while(traverse != NULL) {
        printf("%d", (*traverse).data);
        traverse = (*traverse).next;
    }
    printf("\n");
    return;
}