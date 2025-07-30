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
} VirtualHeap, *VH; //what makes it v4

void initVirtualHeap(VH vh) {
    int i;
    vh->Nodes = (NodeType *)malloc(sizeof(NodeType) * MAX);

    if (vh->Nodes == NULL) {
        printf("memory allocation failed.\n");
        exit(1);
    }

    vh->avail = MAX - 1;  // start from the last index

    // link each node to the previous one
    for (i = MAX - 1; i > 0; i--) {
        vh->Nodes[i].link = i - 1;
    }

    vh->Nodes[0].link = -1;  // end of free list
}

int main() {
    VirtualHeap heap;
    initVirtualHeap(&heap);  // pass address using VH alias
    //more chuchuness here...
    free(heap.Nodes);

    return 0;
}
