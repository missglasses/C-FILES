NodePtr remove_at_pos(Node **head, int pos) {
    // check if list is empty or position is invalid
    if (*head == NULL || pos < 0) {
        return NULL;
    }

    // special case: remove the first node (pos = 0)
    if (pos == 0) {
        NodePtr temp = *head;      //points to head
        *head = (*head)->next;      // updates head to the next node
        temp->next = NULL;          // disconnects the old head
        return temp;                // returns the removed node
    }

    NodePtr current = *head;       //points to head
    NodePtr prev = NULL;            // keesp track of the previous node
    int current_pos = 0;        

    // traverse until reaching the desired position or end of list
    while (current != NULL && current_pos < pos) {
        prev = current;
        current = current->next;
        current_pos++;
    }

    // oob
    if (current == NULL) {
        return NULL;
    }

    // remove the node at 'pos'
    prev->next = current->next;     // skips over current the node to be removed
    current->next = NULL;           // disconnects from the list

    return current;                
}
