#include <stdio.h>
//variation #3

int main() {
    int data[5]={3,4,7,10}; //count is the first element 
    
    //before adding:
     printf("Old array: \n");
    for(int i=0; i<5 ; i++){
          printf("%d ", data[i]);
    }
     printf("\n");
      printf("Added an element: \n");
    if (data[0]<4){ //while data[0] serves as count
    data[data[0]+1]=15; //means <-- data[count+1]=item 
    data[0]++; //increase count
    } else{
        printf("Full na!\n");
    }
    
    
    //after adding:
   for(int i=0; i<5 ; i++){
          printf("%d ", data[i]);
    }
    return 0;
}
