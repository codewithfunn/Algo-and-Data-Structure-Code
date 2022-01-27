#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node* n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
// left -> root -> right
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
        root->right;
    }
    else{
        return 1;
    }
}

// left -> root -> right
void inOrder_traversal(struct node* root){
    if(root!=NULL){
        inOrder_traversal(root->left);
        printf(" %d ",root->data);
        inOrder_traversal(root->right);
    }
}
struct node* BST_Search(struct node* root, int search_value){
    if(root==NULL){
        return NULL;
    }
    if(search_value == root->data ){
        return root;
    }
    else if(search_value < root->data){
        return BST_Search(root->left, search_value);
    }
    else{
        return BST_Search(root->right , search_value);
    }
}
int main(){
    struct node* p  = createNode(5);
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
    // Linking the root with left and right nodes
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // Inorder traversal
    inOrder_traversal(p);
    printf("\n");
    // check this is a binary tree or not
    if(isBST(p)){
        printf("This is a binary search tree!\n");
    }
    else{
        printf("This is not a binary search tree!\n");
    }

    struct node* n = BST_Search(p,4);
    // searching in BST 
    if(n!=NULL){
        printf("Found: %d\n",n->data);
    }
    else{
        printf("Element is not Found!\n");
    }
    return 0 ;
}