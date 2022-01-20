#include <stdio.h>
#include <stdlib.h>
/*
Stack is a collection of element following LIFO. Items can be inserted removed only from one end.
*/
struct stack{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *ptr ){
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

int main(){
    // struct stack s;
    // s.size = 80;
    // s.top = -1;// is empty
    // s.arr = (int *)malloc(s.size * sizeof(int));// creating an arr using dynamic memory

    struct stack *s= (struct stack *)malloc(sizeof(struct stack ));// allocation the memory dynamically using malloc
    s->size = 6;
    s->top = -1;// is empty
    s->arr = (int *)malloc(s->size * sizeof(int));   

    // Check if stack is empty
    if(isEmpty(s)){
        printf("The stack is empty\n");
    }else{
        printf("the stack is not empty\n");
    }


    // // Check if stack is full
    if(isFull(s)){
        printf("the stack is full\n");
    }else{
        printf("the stack is not full\n");
    }
    return 0 ;
}