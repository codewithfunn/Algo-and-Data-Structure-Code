#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};


int isBST(struct node* root){
    static struct node* prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}
struct node* createNode(int data){
    struct node* n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
// left -> root -> right
void InOrder_traversal(struct node *root){
    if(root!=NULL){
        InOrder_traversal(root->left);
        printf(" %d ",root->data);
        InOrder_traversal(root->right);
    }
    else{
        printf("\nyo\n");
    }
}
int main(){
    // Constructing the node using function (Recommended)
    struct node* p = createNode(5);
    struct node* p1 = createNode(3);
    struct node* p2 = createNode(6);
    struct node* p3 = createNode(1);
    struct node* p4 = createNode(4);

    // Finally the tree looks like this:
        //      5
        //     / \
        //    3   6
        //   / \
        //  1   4
    // Linking the root with left and right node
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // InOrder traversal 
    InOrder_traversal(p); 
    printf("\n");
    printf("isBST :: %d\n",isBST(p));
    if(isBST){
        printf("This is a Binary search tree!\n");
    }
    else{
        printf("The input Tree is not a Binary search tree!\n");
    }
    return 0 ;
}