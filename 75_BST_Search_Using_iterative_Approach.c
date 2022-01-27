#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node *createNode(int data){
    struct node* n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
// check this is binary search tree or not
// left -> root -> right
int isBST(struct node* root){
    struct node* prev;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev != NULL && root->data >= prev->data ){
                return 0;
        }
        prev = root;
        root->right;
    }
    return 1;
}

// Search the binary Search tree using iterative approach
struct node* BST_search_iterative(struct node* root , int key){
    while(root!=NULL){
        if(key==root->data){
            return root;
        }
        else if(key < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return NULL;
} 

int main(){
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);

    //finally the tree looks like this
    //          5
    //         / \
    //        3   6
    //       / \
    //      1   6 

    // linking the root node with left and right children
    p->left   = p1;
    p->right  = p1;
    p1->left  = p3;
    p1->right = p4;

    // searching an element using iterative approach
    struct node* n;
    n = BST_search_iterative(p,1);
    if(n!=NULL){
        printf("Found :: %d\n",n->data);
    }
    else{
        printf("Element is not found\n");
    }
    return 0 ;
}