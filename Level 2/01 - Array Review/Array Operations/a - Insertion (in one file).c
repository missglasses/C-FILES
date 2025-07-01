#include <stdio.h>
#define MAX_SIZE 10

//ARRAY
//INSERTION IN ONE FILE

void insertFront(int arr[], int *count, int item){
    
    int i;
    if (*count<MAX_SIZE){
        for(i=*count; i>0; i--){
        arr[i]=arr[i-1];
      
        }
         arr[0]=item;
          (*count)++;
    }
    
}

void insertRear(int arr[], int *count, int item){

    if(*count<MAX_SIZE){
        // arr[(*count)++]=item;
         arr[*count]=item;
         (*count)++;
    }
}

void insertAtPos(int arr[], int *count, int item, int pos){
    int i;
    if (*count<MAX_SIZE){
       for(i=*count; i>pos; i--){
           arr[i]=arr[i-1];
       }
       arr[pos]=item;
       (*count)++;
    }
}

int main (){
    
    int myArr[MAX_SIZE]; //inital element
    int n=0;
    int pos=1;
    
    
    insertFront(myArr,&n, 10);
    insertRear(myArr, &n, 30);
    insertAtPos(myArr, &n, 20, pos); 

  //output: 10,20,30
    
    for(int i=0; i<n; i++){
        printf("%d ", myArr[i]);
    }
    

    return 0;
}
