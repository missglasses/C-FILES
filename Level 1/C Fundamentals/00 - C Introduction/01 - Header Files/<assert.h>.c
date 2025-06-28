#include <stdio.h>
#include <assert.h> //useful ofr debugging

/*ASEERT checks condition @ runtime
if false it prints an error message & terminates the program, by calling abort() */

int divide(int a, int b){
    assert(b!=0);
    return a/b;
}

int main () {
    
    int result = divide(10,2);  
    printf("Result: %d\n", result); //T
    
    /* Example: 
    result = divide(10,0);  
    printf("Result: %d\n", result); assertion failure ; wont execute 
    
    output: Assertion `b!=0' failed. Aborted
    
    */
    return 0;
}
