#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data){
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data =data;
    n->right = NULL;
    n->left  = NULL;
    return n;
}
// root -> left -> right
void preOrder_traversal(struct node * root){
    if(root!=NULL){
        printf(" %d ",root->data);
        preOrder_traversal(root->left);
        preOrder_traversal(root->right);
    }
}
// left -> right -> root
void postOrder_traversal(struct node *root){
    if(root!=NULL){
        postOrder_traversal(root->left);
        postOrder_traversal(root->right);
        printf(" %d ",root->data);
    }
}
// left -> root -> right
void InOrder_traversal(struct node *root){
    if(root!=NULL){
        InOrder_traversal(root->left);
        printf(" %d ",root->data);
        InOrder_traversal(root->right);
    }
}

int main(){
    // Constructing the node using function
    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);

    
    // Finally the tree looks like this:
        //      4
        //     / \
        //    1   6
        //   / \
        //  5   2

    //linking the root node with left and right

      p->left   = p1;
    p->right  = p2;
    p1->left  = p3;
    p1->right = p4;

    
    // Pre Order traversal
    printf("The postOrder traversal is ::\t");
    preOrder_traversal(p);
    
    // Post Order traversal 
    printf("\nThe postOrder traversal is ::\t");
    postOrder_traversal(p);

    // Post Order traversal 
    printf("\nThe InOrder traversal is ::\t");
    InOrder_traversal(p);
    return 0 ;
}