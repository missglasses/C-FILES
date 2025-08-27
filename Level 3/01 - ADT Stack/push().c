void push(Stack *S, char elem){
    //check if full
    if (S->top==MAX_SIZE-1){
        printf("Full");
    }
    
    S->top++; //increment for top pos
    S->elem[S->top]=elem;
}
