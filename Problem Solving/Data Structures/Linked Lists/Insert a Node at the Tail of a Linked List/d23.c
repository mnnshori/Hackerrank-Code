// fix for input n = 0

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
struct LinkedList* createList();
void printListIterative(struct LinkedList* myList);
void insertNodeIterative(struct LinkedList* myList, int data);
void printListRecursive(struct LinkedList* myList);
void _printListRecursive(struct Node* trav);
void insertNodeRecursive(struct LinkedList* myList, int data);
void _insertNodeRecursive(struct Node* trav, int data);
void deleteListIterative(struct LinkedList* myList);

int main() {
    int n;
    struct LinkedList* myList = createList();
    
    while (1) {
        printf("input n: ");
        scanf("%d", &n);
        if(n < 1) {
            printf("Error: n should be greater than 0.\n");
        } else {
            break;
        }
    }

    printf("input linked list elements: ");
    for(int i=0; i<n; i++) {
        int temp;
        scanf("%d", &temp);
        //insertNodeIterative(myList, temp);
        insertNodeRecursive(myList, temp);
    }

    //printListIterative(myList);
    printListRecursive(myList);
    deleteListIterative(myList);
    return 0;
}

struct Node* createNode(int data) {
    struct Node* myNode = (struct Node*)malloc(sizeof(struct Node));

    if(myNode == NULL) { 
        exit(1);
    }
    myNode->data = data;
    myNode->next = NULL;
    return myNode;
}

struct LinkedList* createList() {
    struct LinkedList* myList = (struct LinkedList*)
        malloc(sizeof(struct LinkedList));

    if(myList == NULL) {
        exit(1);
    }

    myList->head = NULL;
    return myList;
}

void printListIterative(struct LinkedList* myList) {
    struct Node* trav = myList->head;
    while(trav != NULL) {
        printf("%d", trav->data);
        trav = trav->next;
        if(trav == NULL) {
            printf("->NULL\n");
        } else {
            printf("->");
        }
    }
    
    return;
}

void insertNodeIterative(struct LinkedList* myList, int data) {
    struct Node* tempNode = createNode(data);

    if(myList->head == NULL) {
        myList->head = tempNode;
        return;
    } else {
        struct Node* trav = myList->head;
        while(trav->next != NULL) {
            trav = trav->next;
        }
        trav->next = tempNode;
        return;
    }
}

void printListRecursive(struct LinkedList* myList) {
    if(myList == NULL) { // INCORRECT
        printf("Error: List is empty.\n");
        return;
    } 

    _printListRecursive(myList->head);
    return;
}

void _printListRecursive(struct Node* trav) {
    if(trav == NULL) {
        return;
    }
    printf("%d", trav->data);
    
    if(trav->next == NULL) {
        printf("->NULL\n");
    } else {
        printf("->");
    }

    _printListRecursive(trav->next);
    return;
}

void insertNodeRecursive(struct LinkedList* myList, int data) {
    if(myList->head == NULL) {
        myList->head = createNode(data);
        return;
    } 
    _insertNodeRecursive(myList->head, data);
    return;
}

void _insertNodeRecursive(struct Node* trav, int data) {

    if(trav->next == NULL) {
        trav->next = createNode(data);
        return;
    }
    
    _insertNodeRecursive(trav->next, data);
    return;
}

void deleteListIterative(struct LinkedList* myList) {

    while(myList->head != NULL) {
        struct Node* tempNode = myList->head;
        myList->head = myList->head->next;

        printf("Freeing node %d...\n", tempNode->data);
        free(tempNode);
    }
    return;
}


