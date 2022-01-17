#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void LinkListTraversal(struct Node *ptr){
    while (ptr!=NULL)
    {
        printf("Element : %d\n",ptr->data);
        //  ptr->next;
        ptr = ptr->next;// assign next ptr address to ptr
    } 
}
// Case 1 : Deleting the first element from the linked list
struct Node * DeleteFirst(struct Node * head){
    struct Node * ptr = head;
    head = head->next;
    free(ptr);// deallocate the memory
    return head;
}
// Case 2 : Deleting the element at the given index from the linked list
struct Node * DeleteAtFirst(struct Node * head , int index){
    struct Node *p = head; // point first element
    struct Node *q = head->next;// point second element
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);    
    return head;
}

// Case 3 : Deleting the last element from the linked list
struct Node * DeleteAtLast(struct Node * head ){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

// Case 4 : Deleting the element with a given value from the linked list
struct Node * DeleteAtIndex(struct Node * head , int value){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->data!=value && q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    if(q->data==value){
        p->next = q->next;
        free(q);
    }
    return head;
}
int main(){
    // declaration
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for node in the linked list in the heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

 
    // link first and second
    head->data = 12;
    head->next = second;
 
    //link second and third 
    second->data = 23;
    second->next = third;
 
    // link third and fourth
    third->data = 14;
    third->next = fourth;
 
    // terminate the link at the fourth node
    fourth->data = 41;
    fourth->next = NULL;
 
    printf("Linked list before deletion!\n");
    LinkListTraversal(head);

    // head = DeleteFirst(head);// for deleting the first element in the linked list
    // head = DeleteAtFirst(head,2);// for deleting the element at given index
    // head = DeleteAtLast(head);// for deleting the last element in the linked list
    head = DeleteAtIndex(head,23);// for deleting the node at a given value
    printf("linked list after deletion!\n");
    LinkListTraversal(head);

    return 0 ;
}