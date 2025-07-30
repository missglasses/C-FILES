#include <stdio.h>
#define MAX 50
typedef struct
{
    char data;
    int link;
} NodeType;

typedef struct
{
    NodeType Nodes[MAX];
    int avail;
} VirtualHeap;

typedef int List;

int main()
{
    VirtualHeap VH;

    initVH(&VH);

    
    //...more code here kapoy
    return 0;
}

void initVirtualHeap(VirtualHeap *vh) {
    int i;

    // set first available index to 0
    vh->avail = 0;

    // loop through all nodes except the last 
    for (i = 0; i < MAX - 1; i++) {
        // link each node to the next one in the array
        //nodes: 0 -> 1 -> 2 -> ... -> max-1
        vh->Nodes[i].link = i + 1;
    }

    //sentinel to indicate last node's link
    vh->Nodes[MAX - 1].link = -1;
}
