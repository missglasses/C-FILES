#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *link;
} cellType, *LIST;

void insertLast(LIST *L, char elem) {
    LIST newNode = (LIST)malloc(sizeof(cellType));
    newNode->data = elem;
    newNode->link = NULL;
    
    if (*L == NULL) {
       //if list is empty, newnode becomes the head/first node
        *L = newNode; //first node is P 
    } else {
        // traverse until last node
        LIST temp = *L; //temp points to first node
        while (temp->link != NULL) {
            temp = temp->link; //temp points to next node
        }
        // last node will connect to new node
        temp->link = newNode;
    }
}

int main() {
    LIST L = NULL; //empty LL
    
    // init list list: P -> A -> N -> T
    insertLast(&L, 'P');
    insertLast(&L, 'A');
    insertLast(&L, 'N');
    insertLast(&L, 'T');

    printf("Before: ");
    LIST temp = L;
    while (temp != NULL) {
        printf("%c ", temp->data); // P A N T
        temp = temp->link;
    }
    printf("\n");

    insertLast(&L, 'S');

    printf("After insertion: "); 
    temp = L;
    while (temp != NULL) {
        printf("%c ", temp->data); // P A N T S
        temp = temp->link;
    }
    printf("\n");

    return 0;
}
