#include <stdio.h>
#include <stdlib.h>  

#define MAX 50

typedef struct {
    char elem;
    int link;
} NodeType;

typedef struct {
    NodeType *Nodes;  // dynamically alloc
    int avail;        
} VirtualHeap;

void initVirtualHeap(VirtualHeap *VH) {
    int i;

    VH->Nodes = (NodeType *)malloc(sizeof(NodeType) * MAX);

    if (VH->Nodes == NULL) {
        printf("memory allocation failed.\n");
        exit(1);
    }

    VH->avail = MAX - 1;  // start from the last index

    // link each node to the previous one
    for (i = MAX - 1; i > 0; i--) {
        VH->Nodes[i].link = i - 1;
    }

    VH->Nodes[0].link = -1;  // marks the end 
}

int main() {
    VirtualHeap vh;
    initVirtualHeap(&vh);  // pass address of struct

    // ... other logic here

    free(vh.Nodes); 
    return 0;
}
