#include <stdio.h>
#include <string.h>
#define MAX 10

typedef struct
{
    char elem[MAX];
    int count;
} LIST;

void insertFirst(LIST *A, char elem)
{
    if (A->count == MAX)
    {
        printf("Full");
    }

    for (int i = A->count; i > 0; i--)
    {
        A->elem[i] = A->elem[i - 1]; // shift elems to the right
    }

    A->elem[0] = elem; // at first index
    A->count++;
}

int main()
{
    LIST A = {{'A', 'N', 'T', 'S'}, 4}; // init array

    printf("Before: ");
    for (int i = 0; i < A.count; i++)
    {
        printf("%c ", A.elem[i]); // P A N T
    }
    printf("\n");

    insertFirst(&A, 'P');

    printf("After inserting 'L' at pos 1: ");
    for (int i = 0; i < A.count; i++)
    {
        printf("%c ", A.elem[i]); // P A N T S
    }
    printf("\n");

    return 0;
}
