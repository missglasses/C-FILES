#include <stdio.h>
// NOTE: This is not a simple value swap or reverse operation, 
// but follows a specific rearrangement pattern:
    // 1 → 5
    // 2 → 4
    // 3 → 2
    // 4 → 1
    // 5 → 3

int getValue();
void swapDisplay(int *a, int *b, int *c, int *d, int *e);

int main() {
      int a, b, c, d, e;

    a = getValue();
    b = getValue();
    c = getValue();
    d = getValue();
    e = getValue();
    
    printf("\nOriginal values:\n");
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    printf("c: %d\n", c);
    printf("d: %d\n", d);
    printf("e: %d\n", e);
    
    swapDisplay(&a, &b, &c, &d, &e);
    
    printf("FIRST VALUE IS NOW: %d\n", a);
    printf("SECOND VALUE IS NOW: %d\n", b);
    printf("THIRD VALUE IS NOW: %d\n", c);
    printf("FOURTH VALUE IS NOW: %d\n", d);
    printf("FIFTH VALUE IS NOW: %d\n", e);
    
    
    return 0;
}

int getValue() {
    int num;
    printf("ENTER VALUE: ");
    scanf("%d", &num);
    return num;
}

void swapDisplay(int *a, int *b, int *c, int *d, int *e){
    int temp1=*a;
    int temp2=*b;

    *a = *d; // 4 → 1
    *d = temp2; // 2 → 4
    *b = *c; // 3 → 2
    *c = *e; // 5 → 3
    *e = temp1; // 1 → 5
}


