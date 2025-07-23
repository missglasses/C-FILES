void addFirst(Node **head, int data){
    Node *newNode = malloc(sizeof(Node));
    
    if (newNode==NULL){
        printf("Mem alloc failed");
        exit(1);
    }
    
    newNode->data=data;
    newNode->next = NULL; //points to NULL as last
    
    //if list is empty it becomes the head
    if (*head==NULL){
        *head = newNode;
        return;
    }
    
    Node * current = *head;
    while(current->next!=NULL){
        current = current->next;
    }
    current->next=newNode; //if reached the last, newnode is the last
    
}
    
