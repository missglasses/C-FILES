#include <stdio.h>

#define MAX 50

typedef struct {
    char elem;
    int link;
} nodeType;

typedef struct {
    nodeType Nodes[MAX];  
    int avail;           
} VirtualHeap, *VHeap;

void initVirtualHeap(VHeap VH) {
    int i;

    VH->avail = MAX - 1;  // start from the last index

    // link each node to the previous node
    for (i = MAX - 1; i > 0; i--) {
        VH->Nodes[i].link = i - 1;
    }

    VH->Nodes[0].link = -1;  // marks the end of the free list
}

int main() {
    VirtualHeap vh;
    initVirtualHeap(&vh);  // pass the address of the struct

    return 0;
}
