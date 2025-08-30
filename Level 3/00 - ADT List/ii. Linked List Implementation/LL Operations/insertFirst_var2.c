#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *next;
} Node;

typedef struct {
    Node *head;
    int count;
} List;


List* initialize() {
    List* newList = (List*)malloc(sizeof(List));
    if (newList == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newList->head = NULL;
    newList->count = 0;
    return newList;
}

void insertFirst(List* list, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;
    
    newNode->next = list->head;
    
    list->head = newNode; //head points to newnode 

    list->count++; 
}

void displayList(List* list) {
    printf("List (%d elements): ", list->count);
    Node* temp = list->head;
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(List* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

int main() {
    
    List* myList = initialize();
    if (myList == NULL) {
        return 1;
    }
    
    printf("Initial empty list:\n");
    displayList(myList);

    insertFirst(myList, 'S');
    insertFirst(myList, 'T');
    insertFirst(myList, 'N');
    insertFirst(myList, 'A');
    
    printf("After building list:\n");
    displayList(myList);  // A N T S
    
    insertFirst(myList, 'P');
    
    printf("After inserting 'P':\n");
    displayList(myList);  // P A N T S
    
    freeList(myList);
    
    return 0;
}
