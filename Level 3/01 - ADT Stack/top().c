int top(Stack *S){
    //get/return without actually deleting
    if(S->top==-1){
        printf("Empty");
    }
    
    return S->elem[S->top];
}
