// what is parenthesis Matching
/*If you remember learning mathematics in school, we had BODMAS there,which required you to solve the expressions,first enclosed by brackets, and then the endependent ones. That's the bracket we're referring to. We have th see if the given expression has baloaced brackets which means every opening bracked must have a corresponding closing bracked and vice versa.
Checking if the parentheses are balanced or not must be a cakewalk for humans,Since we have been dealing with this for the whole time. But even we would fail if the expression becomes too large with a great number of parentheses. This is where automating the process helps. And for automation, we need a proper working algorithm.We will see how we accomplish that together.
We'll use stacks to match these parentheses. Lets see how:
1. Assume the expression given to you as a character array.
3*2-(8+1) -> [3 , * , 2 , - , ( , 8 , + , 1 , ) , \0 ]-> array
2. Iterate through the character array and ignore everthing you find other than the opening and the closing parenthesis. Everey time you find an opening parenthesis, push it inside a charater stack. And ever time you find a closing parenthesis, pop from the stack, in which you pushed the opening bracket.

3. Conditions for unbalanced parentheses:
* when you find a closing parenthesis and try achieving the pop operation in the stack, the stack must not become underflow. To match the existing closing parenthesis, at leaast one opening bracket should to pop. If there is no opening bracket inside the stack to pop, we say the expression has unbalanced parentheses.
* For example: the expression (2+3)*6)+1+5 has no opening bracket corresponding to the last closing bracket. Hence unbalanced.
* At EOE, that is, when you reach the end of the expression, and there is still one or more opening brackets left in the stack, and it is not empty, we call these parentheses unbalanced.
* for example: the expression (2+3)*6+(1+5 has 1 opening bracket left in the stack even after reaching the EOE. Hence unbalanced.
*/
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

// peek operation **
char peek(struct stack *ptr, int i){
    int arrayIndex = ptr->top-i+1;
    if(arrayIndex<0){
        printf("Not a valid position for the stack!\n");
        return -1;
    }
    else{
        return ptr->arr[arrayIndex];
    }
}
int parenthesisMatch(char *exp){
    // create and initialize the stack 
    struct stack *sp;
    sp->size =100;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size *sizeof(int));

    for(int i =0; i<exp[i]!='\0'; i++){
        if(exp[i]=='('){
            push(sp,'(');
        }
        else if(exp[i] ==')'){
            if(isEmpty(sp)){
                return 0;
            }
            else{
                pop(sp);
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
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->arr = (char *)malloc(sizeof(char));
    sp->size = 6;
    sp->top = -1;
    // push operation
    // printf("Before Pushing, full: %d\n",isFull(sp));
    // printf("Before Pushing, Empty: %d\n",isEmpty(sp));
    push(sp,'a');
    push(sp,'s');
    push(sp,'d');
    push(sp,'f');
    push(sp,'g');
    push(sp,'h');// Pushed 6 value 
    push(sp,'j');// stack overflow since the size of the stack is 6
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
        printf("the value at position %d is %c\n",j,peek(sp,j));
    }

// check if the parenthesis is matching or not 
    char *exp = "8*(9)";
    if(parenthesisMatch(exp)){
        printf("The parenthesis is matching!\n");
    }   
    else{
        printf("The parenthesis is not matching! Error\n");
    }

    return 0 ;
}