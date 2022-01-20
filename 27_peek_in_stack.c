#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
//push operation
void push(struct stack *ptr , int value){
    if(isFull(ptr)){
        printf("Stack is Overflow! Cannot push %d to the stack\n",value);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }    
}
// pop operation
int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack is Underflow! Cannot pop to the stack\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

// peek operation **
int peek(struct stack *ptr, int i){
    int arrayIndex = ptr->top-i+1;
    if(arrayIndex<0){
        printf("Not a valid position for the stack!\n");
        return -1;
    }
    else{
        return ptr->arr[arrayIndex];
    }
}
int main(){
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->arr = (int *)malloc(sizeof(int));
    sp->size = 6;
    sp->top = -1;
    // push operation
    // printf("Before Pushing, full: %d\n",isFull(sp));
    // printf("Before Pushing, Empty: %d\n",isEmpty(sp));
    push(sp,0);
    push(sp,1);
    push(sp,2);
    push(sp,3);
    push(sp,4);
    push(sp,5);// Pushed 6 value 
    push(sp,6);// stack overflow since the size of the stack is 6
    // printf("After Pushing, full: %d\n",isFull(sp));
    // printf("After Pushing, Empty: %d\n",isEmpty(sp));

    // pop operation 
    // printf("Popped %d from the stack!\n",pop(sp));// Last in first out
    // printf("Popped %d from the stack!\n",pop(sp));// Last in first out
    // printf("Popped %d from the stack!\n",pop(sp));// Last in first out
    // printf("Popped %d from the stack!\n",pop(sp));// Last in first out

    // printing the value from the stack
    for (int j =1 ; j <= sp->top +1; j++)
    {
        printf("the value at position %d is %d\n",j,peek(sp,j));
    }
    

    return 0 ;
}