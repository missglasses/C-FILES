#include <stdio.h>
#include <string.h>
#define MAX 10

typedef struct
{
    char elem[MAX];
    int count;
} LIST;

// insertSOrted

void insertMiddle(LIST *A, char elem)
{
    if (A->count == MAX)
    {
        printf("Full");
    }

    int i, mid = A->count / 2;
    for (i = A->count - 1; i >= mid; i--)
    {
        A->elem[i + 1] = A->elem[i];
    }
    A->elem[mid] = elem;
    A->count++;
}

int main()
{
    LIST A = {{'M', 'P'}, 2}; // init array

    printf("Before: ");
    for (int i = 0; i < A.count; i++)
    {
        printf("%c ", A.elem[i]);
    }
    printf("\n"); // M P

    insertMiddle(&A, 'A');

    printf("After inserting 'L' at pos 1: ");
    for (int i = 0; i < A.count; i++)
    {
        printf("%c ", A.elem[i]); // M A P
    }
    printf("\n");

    return 0;
}
