#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *link;
} cellType, *LIST;

void insertFirst(LIST *L, char elem) {
    LIST newNode = (LIST)malloc(sizeof(cellType)); //  new node points to current first node
    newNode->data = elem;
    newNode->link = *L;  //[1] NULL, [2] L and newnode link points to first node [3] points to prev node (2)....
    *L = newNode;        // [1] L in main points to newnode, [2] L points to 2nd node, [3] points to 3rd node...
}

int main() {
    LIST L = NULL;  //init empty (null) LL
    
    // initial list: A -> N -> T -> S
    insertFirst(&L, 'S');
    insertFirst(&L, 'T');
    insertFirst(&L, 'N');
    insertFirst(&L, 'A');
    
    printf("Before: ");
    LIST temp = L;
    while (temp != NULL) {
        printf("%c ", temp->data);  // A N T S
        temp = temp->link;
    }
    printf("\n");
    
    insertFirst(&L, 'P');
    
    printf("After inserting: ");
    temp = L;
    while (temp != NULL) {
        printf("%c ", temp->data);  // P A N T S
        temp = temp->link;
    }
    printf("\n");
    
    return 0;
}
