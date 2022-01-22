#include <stdio.h>
#include <stdlib.h>
// linear queue 
// index -1 0 1 2 3 4 5
// arr     [0,1,2,3,4,5]
// starting value of f(front)=-1 and r(real)=-1 it means empty arr                
struct queue{
    int size;
    int f;
    int r;
    int *arr;
};
int isFull(struct queue *ptr){
    if(ptr->r == ptr->size-1){
        return 1;
    }    
    else{
        return 0;
    }
}
int isEmpty(struct queue *ptr){
    if(ptr->f == ptr->r){
            return 1;
        }
        else{
            return 0;
        }
}
void Enqueue(struct queue *q, int value){
    if(isFull(q)){
        printf("The queue is Overflow! Cannot insert %d inside the queue\n",value);
    }
    else{
        q->r++;
        q->arr[q->r] = value;
    }
}
int Dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("The Queue is Underflow!\n");
    }else{
        q->f++;
        return q->arr[q->f];
    }
    return a;
}
void QueueTraversal(struct queue *q){
    while(q->f < q->r){
        q->f = q->f+1;
        printf("the element is :: %d\n",q->arr[q->f]);
    }
}
int main(){
    struct queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int*)malloc(q.size * sizeof(int));
    // Enqueue few elements
    Enqueue(&q,0);
    Enqueue(&q,1);
    Enqueue(&q,2);
    Enqueue(&q,3);
    Enqueue(&q,4);
    Enqueue(&q,5);
    printf("Dequeue element %d\n",Dequeue(&q));
    QueueTraversal(&q);

    // for(int i =0 ; i<20; i++ ){
    //     printf("(%d + 1) moduls 6 = %d\n" , i,((i+1)%6));
    // }
    return 0 ;
}