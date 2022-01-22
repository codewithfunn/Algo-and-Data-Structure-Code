#include <stdio.h>
#include <stdlib.h>
struct circularQueue{
    int size;
    int f;
    int r;
    int *arr;
};
void traversal(struct circularQueue *q){
    do{ 
        printf("the Element is :: %d\n",q->arr[(q->f+1)%q->size]);
        q->f =  q->f +1;
    }while((q->f+1)%q->size < (q->r+1)%q->size);
}
int isEmpty(struct circularQueue *q){
    if(q->f == q->r){
        return 1;
    }
    else {
        return 0;
    }
}
int isFull(struct circularQueue *q){
     if(((q->r+1)%q->size)==q->f){
         return 1;
     }
     else{
         return 0;
     }
}
void enqueue(struct circularQueue *q , int value){
    if(isFull(q)){
        printf("Circular Queue is Overflow! Cannot insert %d inside the queue \n",value);
    }
    else{
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = value;
        printf("Enqued element: %d\n",value);
    }
}
int dequeue(struct circularQueue *q){
    if(isEmpty(q)){
        printf("The circular Queue is Underflow!\n");
    }else{
        q->f = (q->f+1)%q->size;
        int value = q->arr[q->f];
        return value;
    }
}
int main(){
    struct circularQueue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int*)malloc(q.size * sizeof(int));
    // Enqueue few element
    enqueue(&q,1);// call by reference
    enqueue(&q,2);
    enqueue(&q,3);
    // enqueue(&q,7);
    // enqueue(&q,8);
    // dequeue few element
    printf("Dequeue element %d\n",dequeue(&q));
    printf("Dequeue element %d\n",dequeue(&q));
    printf("Dequeue element %d\n",dequeue(&q));
    enqueue(&q,4);
    enqueue(&q,5);
    enqueue(&q,6);
    if(isEmpty(&q)){
        printf("circular queue is empty!\n");
    }
    if(isFull(&q)){
        printf("circular queue is full!\n");
    }
    traversal(&q);
    return 0 ;
}