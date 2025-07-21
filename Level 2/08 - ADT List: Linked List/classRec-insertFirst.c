#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "problems.h"

// Changed from insertLast to insertFirst
void insertFirst(Node **head, studentRecord studList, gradeRecords grList) {  
    Node* newNode = malloc(sizeof(Node));
    fullRecord classRec;
    classRec.studentInfo = studList;
    classRec.grades = grList;
    
    newNode->data = classRec;
    newNode->next = *head;  // points to the current head
    *head = newNode;        // update head to point to the new node
}

Node* populate(studentNode* studentListhead, gradeNode* gradeListhead) {
    Node *head = NULL;
    studentNode* studPtr = studentListhead;
    gradeNode* grPtr = gradeListhead;
    
    while(studPtr != NULL && grPtr != NULL) {
        if(studPtr->studentData.idNumber == grPtr->gradeData.idNumber) {
            insertFirst(&head, studPtr->studentData, grPtr->gradeData);
            
            // Move both pointers forward
            studPtr = studPtr->next;
            grPtr = grPtr->next;
        } 
  
        else if (studPtr->studentData.idNumber < grPtr->gradeData.idNumber) {
            studPtr = studPtr->next;
        } 
      
        else {
            grPtr = grPtr->next;
        }
    }
    return head;
}
