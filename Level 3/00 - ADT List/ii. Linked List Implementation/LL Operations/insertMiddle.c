#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *link;
} cellType, *LIST;

void insertMiddle(LIST *L, char elem) {
    LIST newNode = (LIST)malloc(sizeof(cellType));
    newNode->data = elem;
    newNode->link = NULL;
    
    if (*L == NULL) {
        *L = newNode;
        return;
    }
    
    int count = 0;
    LIST temp = *L;
    while (temp != NULL) {
        count++;
        temp = temp->link;
    }
    
    int mid = count / 2;
    
    temp = *L;
    for (int i = 0; i < mid - 1; i++) {
        temp = temp->link;
    }
    
    newNode->link = temp->link;
    temp->link = newNode;
}

int main() {
    LIST L = NULL;
    
    L = (LIST)malloc(sizeof(cellType));
    L->data = 'M';
    L->link = (LIST)malloc(sizeof(cellType));
    L->link->data = 'P';
    L->link->link = NULL;

    printf("Before: ");
    LIST temp = L;
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->link;
    }
    printf("\n");

    insertMiddle(&L, 'A');

    printf("After: ");
    temp = L;
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->link;
    }
    printf("\n");

    return 0;
}
