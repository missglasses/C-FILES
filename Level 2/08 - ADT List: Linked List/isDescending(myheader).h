#ifndef MYHEADER_H
#define MYHEADER_H

// Node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node
Node* createNode(int data);

// Function to insert a node at the end of the list
void insertNode(Node** head, int data);

// Function to print the list
void printList(Node* head);

#endif
