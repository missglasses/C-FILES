//COLLECT PRIME NUMBERS
#include <stdio.h>
#include <stdlib.h>

/*2 -> Divisible only by 2 and 1

3 -> Divisible only by 3 and 1

5 -> Divisible only by 5 and 1

7 -> Divisible only by 7 and 1

11 -> Divisible only by 11 and 1

13 -> Divisible only by 13 and 1

17 -> Divisible only by 17 and 1*/

int isPrime(int num){
    if (num<2) return 0;
    for (int i=2; i*i<=num; i++){
        if(num%i==0) return 0;
    }
    return 1;
}

int* collectPrime(int arr[], int n, int *primeCtr){
    *primeCtr=0;
    
    //prime counter
    for (int i=0; i<n; i++){
        if(isPrime(arr[i])){ //call isPrime func here
            (*primeCtr)++;
        }
    }
    int j=0;
    int *primeArr = malloc(sizeof(int)*(*primeCtr));
    for (int i=0; i<n; i++){
        if(isPrime(arr[i])){ 
            primeArr[j++]=arr[i];
            // j++;
        }
    }
    return primeArr;
}

int main() {
    
    int origArr[]={-1,2,3,4,5,6,7,8,9};
    int n=sizeof(origArr)/sizeof(origArr[0]);
    int primeCtr=0;
    
    int *primeArr = collectPrime(origArr, n, &primeCtr);
    
    printf("Prime numbers: ");
    for (int i=0; i<primeCtr; i++){
       printf("%d ", primeArr[i]);
    }
    printf("\n");
    
    free(primeArr);
    

    return 0;
}
