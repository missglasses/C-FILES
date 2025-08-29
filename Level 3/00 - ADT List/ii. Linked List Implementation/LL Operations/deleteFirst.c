#include <stdio.h>
#include <string.h>
#define MAX 10

typedef struct
{
    char elem[MAX];
    int count;
} LIST;

void deleteFirst(LIST *A)
{
    if (A->count == 0)
    {
        printf("Empty\n");
        return;
    }

    // shift to the left
    for (int i = 0; i < A->count - 1; i++)
    {
        A->elem[i] = A->elem[i + 1];
    }
    
    A->count--;
}

int main()
{
    LIST A = {{'P', 'A', 'N', 'T', 'S'}, 5}; // PANTS

    printf("Before: ");
    for (int i = 0; i < A.count; i++)
    {
        printf("%c", A.elem[i]); // PANTS
    }
    printf("\n");

    deleteFirst(&A); // Delete 'P'

    printf("After deleting first: ");
    for (int i = 0; i < A.count; i++)
    {
        printf("%c", A.elem[i]); // ANTS
    }
    printf("\n");

    return 0;
}
