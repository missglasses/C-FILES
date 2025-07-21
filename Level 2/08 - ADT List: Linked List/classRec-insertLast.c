#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "problems.h"

/*new node , if else traverse, 
then populate func, pointer for student and grade,
while both are not null compare their id, insertlast , call insertfunc
else if studid < grid traverese studptr else if grid > stud traverse*/

/*[Answer No 2] Complete the necessary Parameters*/
void insertLast(Node **head, studentRecord studList, gradeRecords grList){
	/* [Answer No. 3] Write the necessary to be able to insert last into the the
       new fullRecord linked list
    */
    Node* newNode = malloc(sizeof(Node));
    fullRecord classRec;
    classRec.studentInfo = studList;
    classRec.grades = grList;
    
    newNode->data = classRec;
    newNode->next = NULL;
    
    if(*head==NULL){
        *head=newNode;
    } else {
        Node *temp = *head;
        while (temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = newNode;
    }
    
    
    
    
}

Node* populate(studentNode* studentListhead,gradeNode* gradeListhead){
	/* [Answer No. 1] Write the necessary code to merge the data from the
    student linked list and grade linked list.

    
    Traverse both Linked Lists and if there are nodes in the linked list with a
    common id number INSERT it into the LAST of the new fullRecord linked list

    */
    
      Node *head = NULL;
      
      studentNode* studPtr = studentListhead;
      gradeNode* grPtr =gradeListhead;
      
      while(studPtr!=NULL && grPtr!=NULL){
          if(studPtr->studentData.idNumber==grPtr->gradeData.idNumber){
              insertLast(&head, studPtr->studentData, grPtr->gradeData);
              
              //Traverse
              studPtr = studPtr->next;
              grPtr = grPtr->next;
              
          } else if (studPtr->studentData.idNumber<grPtr->gradeData.idNumber){
              studPtr = studPtr->next;
          } else if (studPtr->studentData.idNumber>grPtr->gradeData.idNumber){
              grPtr = grPtr->next;
          }
      }
      return head;
}
