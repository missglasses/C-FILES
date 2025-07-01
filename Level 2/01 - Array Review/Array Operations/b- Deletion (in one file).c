#include <stdio.h>
#define MAX_SIZE 10

//ARRAY
//DELETION IN ONE FILE

void deleteFront(int arr[], int *count){
    
  if (*count==0){
     printf("Array is empty.");
     return;
  }
  
  int i;
  for(i=0; i<*count-1; i++){
      arr[i]=arr[i+1];
  }
  (*count)--;
    
}

void deleteRear(int arr[], int *count){
    if(*count==0){
        printf("Array is empty\n");
          return;
    }
    
    (*count)--;
  
    
}
void deleteAtPos(int arr[], int *count, int pos){
    
  if (pos<0 || pos>=*count){
      printf("Failed\n");
        return;
  }
    int i;
    for(i=pos; i<*count-1; i++){
        arr[i]=arr[i+1];
    }
    (*count)--;
}

int main (){
    
    int myArr[MAX_SIZE]={5, 10,20,30}; 
    int n=3; //init 3 elements
    int pos=1;
    
    printf("Before: ");
    for(int i=0; i<n; i++){
        printf("%d ", myArr[i]);
    }
    printf("\n");
    
    printf("Delete first element: ");
    deleteFront(myArr, &n);
    for(int i=0; i<n; i++){
        printf("%d ", myArr[i]);
    }
    printf("\n");
    
    
    printf("Delete last element: ");
    deleteRear(myArr, &n);
    for(int i=0; i<n; i++){
        printf("%d ", myArr[i]);
    }
    printf("\n");
    
    printf("After: ");
    for(int i=0; i<n; i++){
        printf("%d ", myArr[i]);
    }
    printf("\n");
    

    return 0;
}
