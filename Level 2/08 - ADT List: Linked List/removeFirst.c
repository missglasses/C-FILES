NodePtr removeFirst(Node **head){
    if(*head==NULL){
        return NULL;
    }
    
   
    NodePtr prevHead = *head; //point to the node to be removed
    *head = (*head)->next; //head will now point to next node
    prevHead->next =NULL; //disconnect old head
  
  
  return prevHead;
}
