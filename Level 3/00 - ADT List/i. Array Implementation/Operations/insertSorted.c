#include <stdio.h>
#include <string.h>
#define MAX 10

typedef struct
{
    char elem[MAX];
    int count;
} LIST;

void insertSorted(LIST *A, char elem)
{
    if (A->count == MAX)
    {
        printf("Full\n");
        return;
    }

    int pos;
    for (pos = 0; pos < A->count; pos++)
    {
        if (elem < A->elem[pos])
        {
            break; // pos found
        }
    }

    // shift to the right
    for (int i = A->count - 1; i >= pos; i--)
    {
        A->elem[i + 1] = A->elem[i];
    }

    A->elem[pos] = elem;
    A->count++;
}

int main()
{
    LIST A = {{}, 0}; // init empty array

    insertSorted(&A, 'A');
    insertSorted(&A, 'D');
    insertSorted(&A, 'E');
    insertSorted(&A, 'C');
    insertSorted(&A, 'B');

    printf("Sorted result: ");
    for (int i = 0; i < A.count; i++)
    {
        printf("%c ", A.elem[i]); // A B C D D E
    }
    printf("\n");

    return 0;
}
