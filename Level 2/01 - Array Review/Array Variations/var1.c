#include <stdio.h>
//VARIATION #1
int main() {
    int data[5]={4,7,5};
    int count =3;
    
    for(int i=0; i<count; i++){
          printf("%d", data[i]);
      if (i<count-1){
            printf(",");
      }
    }
    
    return 0;
}
