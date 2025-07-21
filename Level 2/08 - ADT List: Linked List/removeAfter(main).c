#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "myheader.h"

// [ANSWER No. 1] insert your function definition for removeAfter()
NodePtr removeAfter(Node *head, int item){
    if(head==NULL){
    return NULL;
    }
    
    NodePtr current = head;
    while(current->next!=NULL && current->data!=item){
        current = current->next; //tr
    }
    
    if (current==NULL || current->next==NULL){
        return NULL; //no nodes after
    }
    
    NodePtr removedList = current->next;
    current->next=NULL;
    return removedList;
    
}

// the main()
int main() {
    Node* head = NULL;
    int n, item;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input and insert nodes into the list
    for(int i = 0; i < n; ++i) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &item);
        insertNode(&head, item);
    }

    printf("List: ");
    printList(head);

    int ditem;
    Node* removedList = NULL;  //Nodeptr -> node

    printf("\nEnter item: ");
    scanf("%d", &ditem);

    //call func
    removedList = removeAfter(head, ditem);  
                                            

    printf("Orginal List (after delete): ");  
    printList(head);
    printf("Deleted List: ");
    printList(removedList);

    return 0;
}
