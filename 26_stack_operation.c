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
    if(ptr->top == ptr->size -1){
        return 1;
    }
    else{
        return 0;
    }
}

// push operation
void push (struct stack *ptr , int value ){
    if(isFull(ptr)){
        printf("Stack is Overflow! Cannot push %d to the stack \n",value);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
} 
// pop operation
int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop to the stack\n");
        return -1;
    }else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int main(){
    struct stack *sp= (struct stack *)malloc(sizeof(struct stack ));
    sp->arr = (int *)malloc(sp->size * (sizeof(int)));
    sp->size = 6;
    sp->top = -1;
    printf("Stack has been created successfully!\n");

    printf("Before Pushing, full: %d\n",isFull(sp));
    printf("Before Pushing, Empty: %d\n",isEmpty(sp));
    push(sp,0);
    push(sp,1);
    push(sp,2);
    push(sp,3);
    push(sp,4);
    push(sp,5);// --> Pushed 6 Value 
    push(sp,6);//   Stack Overflow since the size of the stack is 6

    printf("After Pushing, full: %d\n",isFull(sp));
    printf("After Pushing, Empty: %d\n",isEmpty(sp));

    printf("Popped %d from the stack!\n",pop(sp));// Last in first out
    printf("Popped %d from the stack!\n",pop(sp));// Last in first out
    printf("Popped %d from the stack!\n",pop(sp));// Last in first out
    printf("Popped %d from the stack!\n",pop(sp));// Last in first out
    return 0 ;
}