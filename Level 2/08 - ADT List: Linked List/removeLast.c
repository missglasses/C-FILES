NodePtr removeLast(Node **head){
    if(*head==NULL){
        return NULL;
    }
    
    if((*head)->next==NULL){
        NodePtr lastNode = *head;
        *head =NULL;
        return lastNode;
    }
    
    NodePtr current = *head;
    
    //traverese to second to the the lest
    while(current->next->next!=NULL){
        current = current->next;
        
    }
    NodePtr lastNode = current->next;
    current->next=NULL;
    
    return lastNode;
}
