
void pop(Stack *S){
    if (S->top==-1){
        printf("Empty");
    }
    S->top--; //removes the top elem
}
