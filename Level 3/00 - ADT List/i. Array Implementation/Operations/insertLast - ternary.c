#include <stdio.h>
#include <string.h>
#define MAX 10

typedef struct
{
    char elem[MAX];
    int count;
} LIST;

void insertLast(LIST *A, char elem)
{
    // TERNARY VERSION
    (A->count < MAX) && (A->elem[A->count] = elem, A->count++);
}

int main()
{
    LIST A = {{'P', 'A', 'N', 'T'}, 4}; // init array

    printf("Before: ");
    for (int i = 0; i < A.count; i++)
    {
        printf("%c ", A.elem[i]); // P A N T
    }
    printf("\n");

    insertLast(&A, 'S');

    printf("After inserting 'L' at pos 1: ");
    for (int i = 0; i < A.count; i++)
    {
        printf("%c ", A.elem[i]); // P A N T S
    }
    printf("\n");

    return 0;
}
