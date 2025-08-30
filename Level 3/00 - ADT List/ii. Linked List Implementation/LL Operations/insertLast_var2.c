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
    newList->head = NULL;
    newList->count = 0;
    return newList;
}

void insertLast(List *L, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
  
    if (L->head == NULL) {
        L->head = newNode; //[1] points to new node then increase count later
    } else {
        Node* temp = L->head; //[2]... points to prev node where head  is pointing
        while (temp->next != NULL) {
            temp = temp->next; 
        }
        temp->next = newNode; //next (link) of prev node points to newnode
    }
    L->count++;
}

void displayList(List *L) {
    printf("List (%d elements): ", L->count);
    Node* temp = L->head;
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(List *L) {
    Node* current = L->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(L);
}

int main() {
    List* L = initialize();
    
    printf("Initial empty list:\n");
    displayList(L);
    
    insertLast(L, 'P');
    insertLast(L, 'A');
    insertLast(L, 'N');
    insertLast(L, 'T');
    
    printf("After building list:\n");
    displayList(L);
    
    insertLast(L, 'S');
    
    printf("After inserting 'S' at end:\n");
    displayList(L);
    
    freeList(L);
    
    return 0;
}
