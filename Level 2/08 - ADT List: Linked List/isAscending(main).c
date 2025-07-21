#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "myheader.h"

// [ANSWER No. 1] insert your function definition for isDesceding()
bool isAscending(Node *head){
    //if node is empty or single node
   if(head==NULL || head->next==NULL){
    return true;
   }

   Node *current = head;
   while(current->next!=NULL){
    if(current->data > current->next->data){
        return false; //means descending not ascending
    }
    current= current->next;
   }

   return true;
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

    // [ANSWER No. 2] Add function call for isDescending()
    if(isAscending(head)){
        printf("The list is in ascending order.");
    } else {
        printf("The list is not in ascending order.");
    }



    return 0;
}
