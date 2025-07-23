void addFirst(Node **head, int data){
    Node *newNode = malloc(sizeof(Node));
    
    if (newNode==NULL){
        printf("Mem alloc failed");
        exit(1);
    }
    
    newNode->data=data;
    newNode->next = *head; //points to head
    
    *head = newNode; //now head points to newNode
}
