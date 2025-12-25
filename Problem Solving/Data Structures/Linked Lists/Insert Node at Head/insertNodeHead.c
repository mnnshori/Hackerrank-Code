#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
};

struct Node* createNode();
struct LinkedList* createList();
void deleteListIterative();
void deleteListRecursive();
void printListIterative();
void printListRecursive();
void insertNodeTailIterative();
void insertNodeTailRecursive();
void insertNodeHeadIterative();
void insertNodeHeadRecursive();

int main() {
    int n;
    struct LinkedList* myList = createList();

    while(1) {
        printf("input n: ");
        scanf("%d", &n);
        if(n < 1) {
            printf("Error: n must be greater than 0.\n");
        } else {
            break;
        }
    }
    for(int i=0; i<n; i++) {
        int temp;
        scanf("%d", &temp);
        insertNodeHeadIterative(myList, temp);
    }
    printListIterative(myList);
    return 0;
}

struct Node* createNode(int data) {
    struct Node* myNode = (struct Node*)malloc(1 * sizeof(struct Node));
    myNode->data = data;
    myNode->next = NULL;
    return myNode; 
}

struct LinkedList* createList() {
    struct LinkedList* myList = (struct LinkedList*)malloc(1 * sizeof(struct LinkedList));
    myList->head = NULL;
    return myList;
}

void deleteListIterative(struct LinkedList* myList) {
    
    while(myList->head != NULL) {
        struct Node* tempNode = myList->head;
        myList->head = myList->head->next;
        free(tempNode);
        tempNode = NULL;
    }
    
    return;
}

void deleteListRecursive(struct LinkedList* myList) {
    if(myList->head == NULL) {
        return;
    }

    
    deleteListRecursiveHelper(myList->head);
}

void deleteListRecursiveHelper(struct Node* trav) {

    if(trav == NULL) {
        return;
    }

    struct Node* tempNode = trav;
    trav = trav->next;
    free(tempNode);
    tempNode = NULL;
    
    deleteListRecursiveHelper(trav);
}



void printListIterative(struct LinkedList* myList) {
    if(myList->head == NULL) {
        printf("Error: List is empty.\n");
    }

    struct Node* trav = myList->head;
    while(trav != NULL) {
        printf("%d", trav->data);
        if(trav->next == NULL) {
            printf("->NULL\n");
        } else {
            printf("->");
        }
        trav = trav->next;
    }
    return;
}

void printListRecursive(struct LinkedList* myList) {
    if(myList->head == NULL) {
        printf("Error: List is empty.\n");
    }

    printListRecursiveHelper(myList->head);
}

void printListRecursiveHelper(struct Node* trav) {
    if(trav == NULL) {
        return;
    }

    printf("%d", trav->data);
    if(trav->next == NULL) {
        printf("->NULL\n");
    } else {
        printf("->");
    }

    printListRecursiveHelper(trav->next);
}



void insertNodeTailIterative() {}

void insertNodeTailRecursive() {}

void insertNodeHeadIterative() {}

void insertNodeHeadRecursive() {}