#include <stdio.h>

int main() {
    int x = 5;
    int *p = &x;
    int **c = &p;  // c is a pointer to pointer to int
    
    printf("x=%d &x=%p\n", x, (void*)&x);
    printf("p=%p &p=%p *p=%d\n", (void*)p, (void*)&p, *p);
    printf("c=%p &c=%p *c=%p **c=%d\n", (void*)c, (void*)&c, (void*)*c, **c);

    /*
    x=5 &x=0x7fff17b7fc2c
    p=0x7fff17b7fc2c &p=0x7fff17b7fc20 *p=5
    c=0x7fff17b7fc20 &c=0x7fff17b7fc18 *c=0x7fff17b7fc2c **c=5
    */

    return 0;
}
