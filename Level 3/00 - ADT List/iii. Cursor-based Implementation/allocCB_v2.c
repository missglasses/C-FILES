#include <stdio.h>
#define MAX 10

typedef struct {
    char data;
    int link;
} Node;

typedef struct {
    Node nodes[MAX];
    int avail;   
} VirtualHeap;

typedef int CList;  

void initVH(VirtualHeap *VH) {
    int i;
    VH->avail = MAX - 1;          

    for (i = VH->avail; i > 0; i--) {
        VH->nodes[i].link = i - 1;   
    }

    VH->nodes[0].link = -1;    
}

int allocSpace(VirtualHeap *VH) {
    int idx = VH->avail;          
    if (idx != -1) {
        VH->avail = VH->nodes[idx].link;  
    }
    return idx;
}

void initList(CList *L) {
    *L = -1;   // empty list
}
//some code here.........


int main() {
    VirtualHeap VH;
    CList myList;

    initVH(&VH);
    initList(&myList);
  
  //the rest of the code............
    return 0;
}
