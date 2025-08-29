#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *link;
} cellType, *LIST;

void insertPos(LIST *L, char elem, int pos) {
    if (pos < 0) {
        printf("Invalid position!\n");
        return;
    }

    LIST newNode = (LIST)malloc(sizeof(cellType));
    newNode->data = elem;
    
    if (pos == 0) {
        newNode->link = *L;
        *L = newNode; 
        return;
    }
    
    LIST current = *L;
    for (int i = 0; i < pos - 1 && current != NULL; i++) {
        current = current->link;
    }
    
    if (current == NULL) {
        printf("Position out of bounds!\n");
        free(newNode);
        return;
    }
    
    newNode->link = current->link;
    current->link = newNode;
}

int main() {
    LIST L = NULL;
    
    insertPos(&L, 'S', 0);
    insertPos(&L, 'T', 1);
    insertPos(&L, 'N', 2);
    insertPos(&L, 'A', 3);
    insertPos(&L, 'P', 0); //PANTS

    printf("Linked list: ");
    LIST temp = L;
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->link; 
    }
    printf("\n");

    insertPos(&L, 'L', 2);

    printf("After inserting 'L' at pos 2: "); //PLANTS
    temp = L;
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->link;
    }
    printf("\n");

    return 0;
}
