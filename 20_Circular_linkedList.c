#include <stdio.h>
#include <stdlib.h>
// Creation
struct Node {
    int data;
    struct Node *next;
};
// traversal
void linkedListTraversal(struct Node * head){
    struct Node *ptr = head;
    do
    {
        printf("Element is :: %d\n",ptr->data);
        ptr = ptr->next;
    } while (ptr!=head);
    
}

// insertion
// Case 1: Insert at the beginning
struct Node* InsertAtFirst(struct Node *head,int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node * p = head->next;
    while(p->next!=head){
        p= p->next;
    }
    // At this point p points to the last node of this circular linked list
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}
// Case 2: Insert in Between at a given index
struct Node * InsertAtIndex(struct Node* head ,int data, int index){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    printf("/n p1 :: %d \n",p->data);

    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        printf("/n p2 :: %d \n",p->data);
    }
    printf("/n p3 :: %d \n",p->data);
    ptr->next = p->next;
    p->next =ptr; 
    return head; 
}
// Case 3: Insert at the end
struct Node * InsertAtEnd(struct Node *head , int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head;
    do
    {
        p = p->next;
    } while (p->next!=head);
    ptr->next = p->next;
    p->next = ptr;
    // printf(" p data is :: %d",p->data);
    return head;
}
// Case 4: Insert after a Node
struct Node * InsertAfterNode(struct Node * head ,struct Node * preNode ,int data ){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = preNode->next;
    preNode->next = ptr;
    return head;  
}
// deletion
// Case 1: Delete the first element from the linked list
struct Node * deleteAtfirst(struct Node *head){
    struct Node *ptr = head;
    struct Node *p = head->next;
    do
    {
        ptr=ptr->next;
        p=p->next;
    } while (p!=head);
 
    head = p->next;
    ptr->next =head;
    free(p);
    return head;
}
// Case 2: Deleting the element at the given index from the linked list 
struct Node * deleteAtIndex(struct Node * head,int index){
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p= p->next;
        q= q->next;
    }
    p->next = q->next;
    // printf("p is now %d\n",p->data);
    // printf("p->next is now %d\n",p->next->data);
    free(q);
   return head;
}
// Case 3: Deleting the last element from the linked list
struct Node * deleteAtLast(struct Node *head){
    struct Node * p = head;
    printf("p is now :: %d\n",p->data);

    struct Node * q = head->next;
    // printf("q is now :: %d\n",q->data);
    while (q->next!=head)
    {   
        printf("1");
        p=p->next;
        q=q->next;
    }
    p->next= q->next;
    free(q);
    // printf("q is now :: %d\n",q->data);
    // printf("p is now :: %d\n",p->data);
    return head;
}
// Case 4: Deleting the element with a given value from the linked list
struct Node * deleteByValue(struct Node * head,int value){
    struct Node *p = head;
    struct Node *q = head->next;

     while(q->data!=value ){
        printf("yes it has\n");
        p = p->next;
        q = q->next;
    }
        p->next=q->next;
        free(q);
        // printf("p is now :: %d\n",p->data);
        // printf("q is now :: %d\n",q->data);
    return head;
}
 

int main(){
    // declaration 
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in heap
    head   = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third  = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    // link first and second
    head->data = 1;
    head->next = second;

    // link second and third
    second->data = 2;
    second->next = third;

    // link third and fourth
    third->data = 3;
    third->next = fourth;

    // link fourth and first
    fourth->data = 4;
    fourth->next = head;
 
    // printf("Traversal before Insertion\n");
    // linkedListTraversal(head); 
    // // head = InsertAtFirst(head,8);// inserting first element
    // // head =  InsertAtIndex(head,4,2); // insert an element in a given index
    // // head = InsertAtEnd(head,5);   // insert an element at the end of the link list
    // // head = InsertAfterNode(head,second,8); // insert an element after a node 
    // printf("Traversal after Insertion\n");
    // linkedListTraversal(head); 


    // printf("Traversal before Deletion\n");
    // linkedListTraversal(head); 
    // // head=deleteAtfirst(head);// delete first element
    // // head = deleteAtIndex(head,2);// deleting an element in a given index 
    // // head =deleteAtLast(head); // delete the last element
    // // deleteByValue(head,4);    // delete an element by value
    // printf("Traversal after Deletion\n");
    // linkedListTraversal(head); 

    return 0 ;
}