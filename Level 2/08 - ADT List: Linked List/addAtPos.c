void add_at_pos(Node **head, int data, int pos) {
    if (pos < 0) {
        return;
    }

    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("MEm alloc failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;

    if (pos == 0 || *head == NULL) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    Node *current = *head;
    int current_pos = 0;

    while (current->next != NULL && current_pos < pos - 1) {
        current = current->next;
        current_pos++;
    }

    new_node->next = current->next;
    current->next = new_node;
}
