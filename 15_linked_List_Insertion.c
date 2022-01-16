#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node * next;
};

// case 1 -> insert at the beginning
struct Node * insertAtFirst(struct Node *head , int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    
    ptr->data = data;
    return ptr;
}

// case 2 -> Insert in between
struct Node * insertAtIndex(struct Node *head , int data, int index){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    // | Data | Address |
    // |7|ptr->0|  |9|ptr->1|  |11|ptr->2|  |66|ptr-3| 

    struct Node *p = head;
    
    int i=0;

    while(i!=index-1){
        p = p->next;
        i++;
    }
    ptr->data=data;
    ptr->next = p->next;
    p->next= ptr;
    return head;
}

// case 3 ->  Insert at the end
struct Node * InsertAtEnd(struct Node *head , int data ){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr->data = data;
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// case 4 -> Insert after a Node
struct Node * InsertAfterNode(struct Node *head , struct Node *prevNode , int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next= ptr;

    return head;
}
void linkedListTraversal(struct Node* ptr){
    while(ptr!=NULL){
    printf("Element: %d\n", ptr->data);
    ptr = ptr->next;
    }
}
int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;


    // Allocating memory for nodes in the linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // link first and second nodes
    head->data=7;
    head->next= second;

    // link second and third nodes
    second->data=9;
    second->next=third;

    // link third and fourth nodes
    third->data=11;
    third->next=fourth;

    // terminate the link at the third node
    fourth->data=66;
    fourth->next = NULL;

    // linkedListTraversal(head);
    // head = insertAtFirst(head,89);
    // printf("\n*****************\n");
    // linkedListTraversal(head);

    // linkedListTraversal(head);
    // head = insertAtIndex(head,98,1);
    // printf("\n*****************\n");
    // linkedListTraversal(head);

    // linkedListTraversal(head);
    // printf("Link List before insertion \n");
    // head = InsertAtEnd(head,87);
    // printf("\nLink List After insertion \n");
    // linkedListTraversal(head);

    linkedListTraversal(head);
    printf("Link List before insertion \n");
    head = InsertAfterNode(head,second,89);
    printf("\nLink List After insertion \n");
    linkedListTraversal(head);
    return 0 ;
}