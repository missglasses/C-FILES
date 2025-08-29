#include <stdio.h>
#include <string.h>
#define MAX 10

typedef struct
{
    char elem[MAX];
    int count;
} LIST;

void insertPos(LIST *A, char elem, int pos)
{
    if (A->count == MAX)
    {
        printf("Full!");
        return;
    }

    if (pos < 0 || pos > A->count)
    {
        printf("Invalid position!");
        return;
    }

    int i;
    for (i = A->count - 1; i >= pos; i--)
    {
        A->elem[i + 1] = A->elem[i]; // shift to the right
    }

    A->elem[pos] = elem;
    A->count++;
}

int main()
{
    LIST A = {{'P', 'A', 'N', 'T', 'S'}, 5}; // init array

    printf("Before: "); //P A N  T S 
    for (int i = 0; i < A.count; i++)
    {
        printf("%c ", A.elem[i]);
    }
    printf("\n");

    insertPos(&A, 'L', 1);

    printf("After inserting 'L' at pos 1: ");
    for (int i = 0; i < A.count; i++)
    {
        printf("%c ", A.elem[i]); //P L A N T S
    }
    printf("\n");

    return 0;
}
