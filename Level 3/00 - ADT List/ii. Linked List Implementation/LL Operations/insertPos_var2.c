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

void insertAt(List *L, int index, char data) {
    if (index < 0 || index > L->count) {
        printf("Index invalid!\n");
        return;
    }
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    if (index == 0) {
        newNode->next = L->head;
        L->head = newNode;
    } else {
        Node* current = L->head; //current points to prev node
        current->next = newNode;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next; 
        current->next = newNode; //prev node link points to new node
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
    
    insertAt(L, 0, 'P');
    insertAt(L, 1, 'A');
    insertAt(L, 2, 'N');
    insertAt(L, 3, 'T');
    insertAt(L, 4, 'S');
    
    printf("Before insertion:\n");
    displayList(L);
    
    insertAt(L, 1, 'L');
    
    printf("After inserting 'L' at index 1:\n");
    displayList(L);
    
    freeList(L);
    
    return 0;
}
