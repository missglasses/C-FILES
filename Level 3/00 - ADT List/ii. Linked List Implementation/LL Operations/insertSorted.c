#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *link;
} cellType, *LIST;

void insertSorted(LIST *L, char elem) {
    LIST newNode = (LIST)malloc(sizeof(cellType));
    newNode->data = elem;
    newNode->link = NULL;
    
    if (*L == NULL || elem < (*L)->data) {
        newNode->link = *L;
        *L = newNode;
        return;
    }
    
    LIST current = *L;
    while (current->link != NULL && current->link->data < elem) {
        current = current->link;
    }
    
    newNode->link = current->link;
    current->link = newNode;
}

int main() {
    LIST L = NULL;

    insertSorted(&L, 'A');
    insertSorted(&L, 'D');
    insertSorted(&L, 'E');
    insertSorted(&L, 'C');
    insertSorted(&L, 'B');

    printf("Sorted result: ");
    LIST temp = L;
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->link;
    }
    printf("\n");

    return 0;
}
