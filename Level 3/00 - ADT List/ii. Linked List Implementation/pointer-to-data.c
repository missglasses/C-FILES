#include <stdio.h>
#include <stdlib.h>
//POINTER TO DATA
typedef struct node
{
    char data;
    struct node *link;
} cellType, *LIST;

int main()
{
    LIST L;

    L = (LIST)malloc(sizeof(cellType));
    L->data = 'M';

    L->link = (LIST)malloc(sizeof(cellType));
    L->link->data = 'B';

    L->link->link = (LIST)malloc(sizeof(cellType));
    L->link->link->data = 'C';
    L->link->link->link = NULL;

    // traverse
    printf("Linked list contents:\n");
    LIST trav = L;
    while (trav != NULL)
    {
        printf("Data: %c\n", trav->data);
        trav = trav->link;
    }

    return 0;
}
