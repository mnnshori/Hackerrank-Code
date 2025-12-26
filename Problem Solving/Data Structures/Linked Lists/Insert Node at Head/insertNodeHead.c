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

void deleteListIterative(struct LinkedList* myList);
void printListIterative(struct LinkedList* myList);

void insertNodeHead(struct LinkedList* myList, int data);
void clearBuffer();

int main() {
    int n = -1;
    struct LinkedList* myList = createList();

    while(1) {
        printf("input n: ");
        int scanfOutput;
        scanfOutput = scanf("%d", &n);
        //printf("scanfOutput = %d\n", scanfOutput);

        if(scanfOutput != 1) {
            printf("Error: n must be an integer greater than 0.\n");
            clearBuffer();
        } else {
            if(n < 1) {
                printf("Error: n must be greater than 0.\n");
            } else {
                break;
            }
        }
    }
    printf("input Linked List elements: ");
    for(int i=0; i<n; i++) {
        int temp;
        scanf("%d", &temp);
        insertNodeHead(myList, temp);
    }
    printListIterative(myList);
    deleteListIterative(myList);
    myList = NULL;

    return 0;
}

struct Node* createNode(int data) {
    struct Node* myNode = (struct Node*)malloc(1 * sizeof(struct Node));

    if(myNode == NULL) {
        exit(1);
    }

    myNode->data = data;
    myNode->next = NULL;
    return myNode; 
}

struct LinkedList* createList() {
    struct LinkedList* myList = (struct LinkedList*)malloc(1 * sizeof(struct LinkedList));

    if(myList == NULL) {
        exit(1);
    }

    myList->head = NULL;
    return myList;
}

void deleteListIterative(struct LinkedList* myList) {

    if(myList == NULL) {
        return;
    }
    
    while(myList->head != NULL) {
        struct Node* tempNode = myList->head;
        myList->head = myList->head->next;
        free(tempNode);
    }

    free(myList);
    
    return;
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

void insertNodeHead(struct LinkedList* myList, int data) {

    if(myList == NULL) {
        exit(1);
    }

    struct Node* newNode = createNode(data);
    if(newNode == NULL) {
        exit(1);
    }

    newNode->next = myList->head;
    myList->head = newNode;
    return;
}

void clearBuffer() {
    int n;
    while( (n = getchar()) != '\n' && n != EOF);
}

