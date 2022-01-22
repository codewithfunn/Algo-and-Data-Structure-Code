#include <stdio.h>
#include <stdlib.h>
// struct of Queue linked list
struct Node{
    int data;
    struct Node *next;
};
// making it as a global variable
    struct Node *f= NULL;
    struct Node *r = NULL;

int isFull(struct Node *ptr){
    if(ptr==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(){
    if(f==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue( int value){
    struct Node * n = (struct Node*)malloc(sizeof(struct Node));
    if(isFull(n)){
        printf("The Qneque is Overflow! Cannot insert %d inside the queue\n",value);
    }
    else{
        n->data = value;
        n->next = NULL;
        if(isEmpty()){
            f=r=n;
        }
        else{
            r->next = n;
            r=n;
        }
    }
}

int dequeue(){
    struct Node *ptr = f;
    // check if queue is empty or not
    if(isEmpty(f)){
        printf("The queue is Empty! cannot delete an element from it\n");
        return -1;
    }
    else{
        f = f->next;
        int val = ptr->data;
        free(ptr);
        return val;
    }
    return -1;
}
void QueueTraversal(struct Node *ptr){
    if(isEmpty()){
        printf("The queue is Empty\n");
    }else{
    printf("Printing the elements of this linked list\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
    }
}
int main(){
    // // traversal before insertion
    // QueueTraversal(f);
    // // insertion
    enqueue(0);    
    enqueue(1);    
    enqueue(2);    
    // traversal after insertion
    // QueueTraversal(f);
    
    // traversal before deletion
    QueueTraversal(f);
    // deletion
    printf("Dequeue element is %d\n",dequeue());
    printf("Dequeue element is %d\n",dequeue());
    printf("Dequeue element is %d\n",dequeue());
    // traversal after deletion
    QueueTraversal(f);
    return 0 ;
}