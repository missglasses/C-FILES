#include <stdio.h>
#include <string.h>
#define MAX 10

typedef struct
{
    char elem[MAX];
    int count;
} LIST;

void deleteLast(LIST *A)
{
    if (A->count == 0)
    {
        printf("Empty\n");
        return;
    }

    A->count--; 
}

int main()
{
    LIST A = {{'P', 'A', 'N', 'T', 'S'}, 5}; 

    printf("Before: ");
    for (int i = 0; i < A.count; i++)
    {
        printf("%c", A.elem[i]); // PANTS
    }
    printf("\n");

    deleteLast(&A); // Delete 'S'

    printf("After deleting last: ");
    for (int i = 0; i < A.count; i++)
    {
        printf("%c", A.elem[i]); // PANT
    }
    printf("\n");

    return 0;
}
