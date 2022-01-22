#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
// Infix , Prefix and Postfix Expression
what are these?
The three terms, infix prefix and postfix will be dealt with individually later. In general, these are the notations to write an expression, Mathematical expression have been taught to us since childhood. Writing expressions to add two numbers for subtraction,multiplication or division. They were all expressed through certain expressions. 
Infix:
This is the method we have all been studying and applying for all our academic life. Here the operator comes in between two operands. And we say, two is added to three. for eg. 2+3,a*b,6/3 etc.
<operand 1><operator>< operand 2>
Prefix:
This method might seem new to you, but we have vocally used them a lot as well. Here the operator comes before the two operands. And we say, Add two and three, for eg : + 6 8, * x y , -3 2 etc.
<operator><operand 1><operand 2>
Postfix:
This is the method that might as well seem new to you,but we have used even this in our communication. Here the operator comes after the two operands. And we say, Two and three are added. for 
    Eg: 5 7 + , a b * ,1 2 6 / etc.
<operand 1><operand 2><operator>
To understand the interchangeability of these terms, please refer to the table below:
Sno     Infix       Prefix      Postfix
1.      a*b         *ab         ab*
2.      a-b         -ab         ab-
*/
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
// stackTop
char stackTop(struct stack *ptr){
    return ptr->arr[ptr->top];
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
int precedence(char ch){
    if(ch=='*'||ch=='/'){
        return 3;
    }
    else if(ch=='+' || ch =='-'){
        return 2;
    }
    else{
        return 0;
    }
}
int isOperator(char ch){
    if(ch=='+'||ch=='-'||ch=='/'||ch=='*'){
        return 1;
    }
    else{
        return 0;
    }
}
char *infixToPostFix(char * infix){
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size *sizeof(char));

    char *postfix = (char *)malloc((strlen(infix)+1) *sizeof(char));
    int i=0; // Track infix traversal
    int j=0; // Track postfix addition
    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;
        }
        if(precedence(infix[i]) > precedence(stackTop(sp))){
            push(sp,infix[i]);
            i++;
        }
        else{
            postfix[j] = pop(sp);
            j++;
        }
    }
    while(!isEmpty(sp)){
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
int main(){ 
    char * infix = "a-b+t/6";
    printf("postfix is %s \n" , infixToPostFix(infix));



    return 0 ;
}
// check if the parenthesis is matching or not 
    // char *exp = "{8*(9)}";
    // if(parenthesisMatch(exp)){
    //     printf("The parenthesis is balanced!\n");
    // }   
    // else{
    //     printf("The parenthesis is not balanced! Error\n");
    // }
    