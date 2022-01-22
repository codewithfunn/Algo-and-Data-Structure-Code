#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node * next;
};
struct Node *top=NULL;// making Node top as a global variable

// traversal
void traversal(struct Node *ptr){
    while(ptr!=NULL){
        printf("Element is :: %d\n",ptr->data);
        ptr = ptr->next;
    }
}
// isEmpty
int isEmpty(struct Node *top){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}
// isfull
int isFull(struct Node *top){
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
 
//push operation
struct Node * push(struct Node *top, int data){
    if(isFull(top)){
        printf("The strack is Overflow! Connot insert %d in the strack\n",data);
        // return -1;
    }
    else{
        struct Node * n = (struct Node *)malloc(sizeof(struct Node));
        n->data = data;        
        n->next = top;
        top = n;
        return top;
    }
}
// pop operation
int  pop(struct Node *tp){
    if(isEmpty(tp)){
        printf("The stack is Underflow! Cannot perform pop operation on the stack");
        return -1;
    }else{
        struct Node *n = tp;
        top = tp->next; // de-refernce nd next 
        int data = n->data;
        free(n);
        return data;
    }
}
// peek operation

int peek(struct Node *top, int pos){
    struct Node * ptr = top;
    for(int i=0; (i<pos-1 && ptr!=NULL); i++){
        ptr = ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;
    }
    else{
        return -1;
    }
}
// stack top
int stackTop(struct Node * top){
    if(isEmpty(top)){
        printf("The stack is empty!");
        return -1;
    }
    else{
        return top->data;
    }
}
// stack bottom
int stackBottom(struct Node *top){
    // struct node *p = top->next;
    while(top->next!=NULL){
        top = top->next;
    }
    return top->data;
}
int main(){
    // |top|->| data | ptr |-->| data | ptr |-->|data | ptr |-->NULL
   
    top = push(top , 0);
    top = push(top , 1);
    top = push(top , 2);
    top = push(top , 3);
    printf("popped element is %d\n",pop(top));
    traversal(top);
    // int pos = 2;
    
    for(int i=0; i<4;i++){
    printf("the data at pos : %d is %d\n",i,peek(top,i));
    }

    printf("the value at the end is %d\n",stackBottom(top));
    printf("the value at the first Node is %d\n",stackTop(top));
    return 0 ;
}