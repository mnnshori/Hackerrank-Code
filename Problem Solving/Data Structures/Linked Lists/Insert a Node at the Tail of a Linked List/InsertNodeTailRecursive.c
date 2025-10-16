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
void freeListRecursive(struct Node* ptr);
void deleteList(struct LinkedList* myList);

int main() {
    struct LinkedList* myList = createLinkedList();
    int n;
    printf("input n: ");
        

    if(scanf("%d", &n) != 1) {
        fprintf(stderr, "Error reading number of elements.\n");
        free(myList);
        return 1;
    }

    printf("input %d numbers: ", n);
    for(int i=0; i<n; i++) {
        int temp;
        

        if( scanf("%d", &temp ) != 1) {
            fprintf(stderr, "Error reading element.\n");
            deleteList(myList);
            return 1;
        }

        insertNodeTail(myList, temp);
    }
    printList((*myList).listHead);

    deleteList(myList);
    return 0;
}

struct Node* createNode(int data) {
    struct Node* myNode = (struct Node*)realloc(NULL, 1 * sizeof(struct Node));

    if(myNode == NULL) {
        perror("Failed to allocate memory for Node");
        exit(EXIT_FAILURE);
    }

    (*myNode).data = data;
    (*myNode).next = NULL;
    return myNode;
}

struct LinkedList* createLinkedList() {
    struct LinkedList* myList = (struct LinkedList*)realloc(NULL, 1 * sizeof(struct LinkedList));

    if(myList == NULL) {
        perror("Failed to allocate memory for struct LinkedList");
        exit(EXIT_FAILURE);
    }

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

void freeListRecursive(struct Node* ptr) {
    if(ptr == NULL) {
        return;
    }

    printf( "reached %d...\n", (*ptr).data );
    freeListRecursive( (*ptr).next );
    
    printf( "freeing up %d...\n", (*ptr).data );
    free(ptr);
}

void deleteList(struct LinkedList* myList) {
    if( myList == NULL) {
        return;
    }
    freeListRecursive((*myList).listHead);
    
    (*myList).listHead = NULL;
    free(myList);
}
