#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "myheader.h"

// [ANSWER No. 1] insert your function definition for isDesceding()
bool isDescending(Node *head){
    //if node is empty or single node
    if(head==NULL || head->next==NULL){
        return true;
    
    
    Node *current=head;
    if (current->data<current->next->data){
        return false ; //increase not descending
    }
    current = current->next;// traverse
    }
    return true; //if all are in descenfing ord
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
   
   if (n > 0) {
    if (isDescending(head)) {
        printf("The list is in descending order.\n");
    } else {
        printf("The list is not in descending order.\n");
    }



    return 0;
}
