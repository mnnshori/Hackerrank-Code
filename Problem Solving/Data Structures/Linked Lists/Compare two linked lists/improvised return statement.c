#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
};

void printArray(int* myArray, int arrayLength);
struct LinkedList* createList();
struct Node* createNode(int data);
void addNodeAtEnd(struct LinkedList* myList, int data);
void printList(struct LinkedList* myList);
bool compareLists(struct LinkedList* list1, struct LinkedList* list2);
 

int main() {
    int testCases;
    printf("input total number of test cases: ");
    scanf("%d", &testCases);

    for(int t=0; t<testCases; t++) {
        int list1Length;
        printf("input list1 length: ");
        scanf("%d", &list1Length);
    
        struct LinkedList* list1 = createList();
    
        printf("input list1 elements: ");
        for(int i=0; i<list1Length; i++) {
            int temp;
            scanf("%d", &temp);
            addNodeAtEnd(list1, temp);
        }
        printList(list1);

        int list2Length;
        printf("input list2 length: ");
        scanf("%d", &list2Length);
    
        struct LinkedList* list2 = createList();
    
        printf("input list1 elements: ");
        for(int i=0; i<list2Length; i++) {
            int temp;
            scanf("%d", &temp);
            addNodeAtEnd(list2, temp);
        }
        printList(list2);

        bool result = compareLists(list1, list2);
        if(result == true) {
            printf("lists are same\n");
        } else {
            printf("lists are different\n");
        }
    }
    
    return 0;
}

struct LinkedList* createList() {
    struct LinkedList* myList = (struct LinkedList*)realloc(NULL, 1 * sizeof(struct LinkedList));
    (*myList).head = NULL;
    return myList;
}

struct Node* createNode(int data) {
    struct Node* myNode = (struct Node*)realloc(NULL, 1 * sizeof(struct Node));
    (*myNode).data = data;
    (*myNode).next = NULL;
    return myNode;
}

void printArray(int* myArray, int arrayLength) {
    printf("printing array...\n");
    for(int i=0; i<arrayLength; i++) {
        printf("%d ");
    }
    printf("\n");
    return;
}

void addNodeAtEnd(struct LinkedList* myList, int data) {
    struct Node* myNode = createNode(data);

    if((*myList).head == NULL) {
        (*myList).head = myNode;
        return;
    } else {
        struct Node* current = (*myList).head;

        while((*current).next != NULL) {
            current = (*current).next;
        }
        (*current).next = myNode;
        return;
    }
}

void printList(struct LinkedList* myList) {
    struct Node* current = (*myList).head;
    printf("printing list...\n");
    
    while(current != NULL) {
        printf("%d ", (*current).data);
        current = (*current).next;
    }

    printf("\n");
}

bool compareLists(struct LinkedList* list1, struct LinkedList* list2) {
    struct Node* current1 = (*list1).head;
    struct Node* current2 = (*list2).head;

    if(current1 == NULL && current2 == NULL) {
        return true;
    }
    
    while(current1 != NULL && current2 != NULL) {
        if((*current1).data != (*current2).data) {
            return false;
        }
        current1 = (*current1).next;
        current2 = (*current2).next;
    }
    return current1 == current2;
}