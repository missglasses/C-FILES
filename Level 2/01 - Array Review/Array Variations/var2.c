#include <stdio.h>
//variation #2

int main() {
    int data[5]={4,7,10,-1}; //-1 as the delimiter

    
    for(int i=0; data[i]!=-1; i++){
          printf("%d ", data[i]);
    }
    
    return 0;
}
