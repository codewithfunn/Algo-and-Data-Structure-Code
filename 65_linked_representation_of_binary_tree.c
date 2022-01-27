#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * left;
    struct node * right;
};
struct node * createNode(int data){
    struct node *n; // Creating a node pointer
    n = (struct node*)malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data; // Setting the data
    n->left = NULL; // Setting the left children to NULL
    n->right = NULL;// Setting the right children to NULL
    return n; // Finally returning the created node
}
int main(){
    // // Constructing the root node
    // struct node *p;
    // // Allocating memory in heap
    // p = (struct node *)malloc(sizeof(struct node));
    // p->data = 2;
    // p->left = NULL;
    // p->right =NULL;

    // // Constructing the second node
    // struct node *p1;
    // // Allocating memory in heap
    // p1 = (struct node *)malloc(sizeof(struct node));
    // p1->data =1;
    // p1->left = NULL;
    // p1->right = NULL;

    // // Constructing the third node
    // struct node *p2;
    // // Allocating memory in heap
    // p2 = (struct node *)malloc(sizeof(struct node));
    // p2->data = 4;
    // p2->left = NULL;
    // p2->right = NULL;

    // // linking the root node with left and right children
    // p->left = p1;
    // p->right = p2;

    // Constructing the root node - Using function (Recommended)
    struct node *p = createNode(2);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(4);
    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    return 0 ;
}