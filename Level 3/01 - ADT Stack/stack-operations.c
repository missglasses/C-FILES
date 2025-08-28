#include <stdio.h>
#define MAX_SIZE 5

typedef struct {
     char elem[MAX_SIZE];
     int top;
}Stack;

void initStack(Stack *S){
    S->top = -1;
}
void push(Stack *S, char elem){
    //check if full
    if (S->top==MAX_SIZE-1){
        printf("Full");
    }
    
    S->top++; //increment for top pos
    S->elem[S->top]=elem;
}

int top(Stack *S){
    //get/return without actually deleting
    if(S->top==-1){
        printf("Empty");
    }
    
    return S->elem[S->top];
}

void pop(Stack *S){
    if (S->top==-1){
        printf("Empty");
    }
    S->top--; //removes the top elem
}
int main() {
    
   Stack S;
   initStack(&S);
   
    push(&S,'B');
    push(&S,'A');
    top(&S);
   
    printf("First top element element: %c\n", top(&S));
   
    pop(&S);
    printf("After popping, top element: %c\n", top(&S));
   
    //MAKE IT EMPTYYYY
    pop(&S);
    pop(&S);
    
 
    // printf("Top element after popping all: %c\n", top(&S));
   

    return 0;
}
