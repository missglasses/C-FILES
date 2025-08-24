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
    VH->avail = 0;
    for (i = 0; i < MAX - 1; i++) {
        VH->nodes[i].link = i + 1;  // populates link 1-n until max-1
    }
    VH->nodes[MAX - 1].link = -1;  //indicates last
}

void initList(CList *L) {
    *L = -1; //means empty
}

int allocSpace(VirtualHeap *VH) {
    int idx = VH->avail;
    if (idx != -1) {
        VH->avail = VH->nodes[idx].link;  //update avail to point to the next free node (from 0 to 1 at first)
    }
    return idx; 
}

//some code...........
int main() {
    VirtualHeap VH;
    CList myList;

    initVH(&VH);
    initList(&myList);
    //the rest of the code...

    return 0;
}
