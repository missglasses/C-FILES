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
        VH->nodes[i].link = i + 1;  // populates link 1-n until not max-1
    }
    VH->nodes[MAX - 1].link = -1;  //indicates last
}

void initList(CList *L) {
    *L = -1; //means empty
}

int allocSpace(VirtualHeap *VH) {
    int idx = VH->avail;
    if (idx != -1) {
        VH->avail = VH->nodes[idx].link;  
    }
    return idx; 
}

void freeSpace(VirtualHeap *VH, int idx) {
    VH->nodes[idx].link = VH->avail;
    VH->avail = idx;
}

void insertFirst(VirtualHeap *VH, CList *L, char elem) {
    int newNode = allocSpace(VH);
    if (newNode != -1) {
        VH->nodes[newNode].data = elem; 
        VH->nodes[newNode].link = *L; ///if not empty, this points to the previous first node
        *L = newNode; //head of the list is updated to the new node--now the new node becomes the first element in the list.
    } else {
        printf("No more space!\n");
    }
}

void displayList(VirtualHeap VH, CList L) {
    printf("List: ");
    while (L != -1) {
        printf("%c -> ", VH.nodes[L].data);
        L = VH.nodes[L].link;
    }
    printf("NULL\n");
}

int main() {
    VirtualHeap VH;
    CList myList;

    initVH(&VH);
    initList(&myList);

    insertFirst(&VH, &myList, 'A');
    insertFirst(&VH, &myList, 'B');

    displayList(VH, myList);

    return 0;
}
