#include <stdio.h>
#include<stdlib.h>
// Creation
struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};
// forward traversal
void forwardTraversal(struct Node *head){
    struct Node * ptr = head;
    // printf("head :: %d\n",head->data);
    while(ptr!=NULL){
        printf("Element is :: %d\n",ptr->data);
        ptr=ptr->next;
    }
}
// backward traversal
void backwardTraversal(struct Node *head){
    struct Node *ptr = head;
    while(ptr!=NULL){
        printf("Element is :: %d\n",ptr->data);
        ptr=ptr->prev;
    }
}

// Insertion 

// Case1: Insert at the begining
struct Node *InsertAtFirst(struct Node *head,int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    ptr->prev = NULL;
    head->prev= ptr;
    head = ptr;
    return head;
}

// Case2: Insert at Between in the given index
struct Node *InsertAtIndex(struct Node *head , int index, int data){
    struct Node *ptr =(struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    // printf(" p is :: %d\n ", p->data);
    // printf(" q is :: %d\n",q->data);
    if(q!=NULL&&p!=NULL){
    // right node
    p->next = ptr;
    ptr->prev = p;

    // left node
    q->prev = ptr;
    ptr->next = q;
    }
    else{
        printf("Error!");
    }
    return head;
}

// Case 3: Insert at the end of the doubly link list
struct Node * InsertAtEnd(struct Node *head,int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    // struct Node *q = head->next;
    while(p!=NULL){
        printf("p is :: %d\n",p->data);
        p = p->next;
    }
    p=ptr;
    printf("p1 is :: %d\n",p->data);

    ptr->prev = p;
    printf("p2 is :: %d\n",p->prev->data);

    ptr->next = NULL;
    printf("p3 is :: %d\n",p->data);
    return head;
}
int main(){
// declaration
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

// allocate dynamic memory in the heap
    head   = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third  = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));


    // link the first to second
        head->data = 1;
        head->next = second;
    // link the second to third
        second->data = 2;
        second->next = third;
    // link the third to fourth
        third->data = 3;
        third->next = fourth;
    // link the fourth to Null
        fourth->data = 4;
        fourth->next = NULL;    

    // link the first to Null
        head->prev = NULL;
    // link the second to first
        second->prev = head;
    // link the third to second
        third->prev = second;
    // link the fourth to third
        fourth->prev = third;

    // // forward traversal 
    //     forwardTraversal(head);
    // // backward traversal 
    //     printf("\n********************\n");
    //     backwardTraversal(fourth);
        printf("\n**** before insertion ****************\n");
        forwardTraversal(head);
        // head =InsertAtFirst(head,0);
        // InsertAtIndex(head,4,23);
        head = InsertAtEnd(head,5);
        printf("\n**** after  insertion ****************\n");
        forwardTraversal(head);
        // backwardTraversal(fourth);
    return 0 ;
}