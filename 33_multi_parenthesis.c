#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    char *arr;
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
void push(struct stack *ptr , char value){
    if(isFull(ptr)){
        printf("Stack is Overflow! Cannot push %c to the stack\n",value);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }    
}
// pop operation
char pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack is Underflow! Cannot pop to the stack\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
 
int match(char a, char b){
    if(a =='('&& b==')'){
        return 1;
    }
    if(a == '{' && b =='}'){
        return 1;
    }
    if(a=='[' && b ==']'){
        return 1;
    }
    return 0;
}
int parenthesisMatch(char *exp){
    // create and initialize the stack 
    struct stack *sp;
    sp->size =100;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size *sizeof(int));
    char popped_ch;
    for(int i =0; i<exp[i]!='\0'; i++){
        if(exp[i]=='('|| exp[i]=='{' ||exp[i]== '['){
            push(sp,exp[i]);
        }
        else if(exp[i] ==')'|| exp[i]=='}' || exp[i]==']'){
            if(isEmpty(sp)){
                return 0;
            }
            popped_ch = pop(sp);
            if(!match(popped_ch,exp[i])){
                    return 0;
            }
        }
    }
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }

}
int main(){
// check if the parenthesis is matching or not 
    char *exp = "{8*(9)}";
    if(parenthesisMatch(exp)){
        printf("The parenthesis is balanced!\n");
    }   
    else{
        printf("The parenthesis is not balanced! Error\n");
    }

    return 0 ;
}