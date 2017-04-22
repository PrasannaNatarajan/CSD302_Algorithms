/*
Name    	:   Prasanna Natarajan
Roll Number :   1410110298
Inputs  	:   The values to insert and delete into the data structure
Outputs 	:   The values properly inserted and deleted
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>


//defining global variables
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node_t;

int count = 0;
int result = -1;

//declaring functions
node_t *createNode(int data);
void printTree(node_t *root);
node_t* insert(node_t *root,int data);
node_t *delete(node_t *root,int data);
int findSmallest(node_t *root,int k);
void traverse(node_t *root, int k);

int main(){

    node_t* root = NULL;

    //testing insertion
    root = insert(root,10);
    root = insert(root,5);
    root = insert(root,4);
    root = insert(root,4);
    root = insert(root,6);
    root = insert(root,12);
    root = insert(root,15);

    //printing the tree
    printTree(root);
    printf("\n");

    //testing deletion
    root = delete(root,10);

    //printing the tree after deletion
    printTree(root);
    printf("\n");

    //testing find_smallest
    int k = 5;
    printf("min = %d",findSmallest(root,k));
    return 0;
}

//function to find the kth smallest element
int findSmallest(node_t *root, int k) {
    traverse(root,k);
    return result;
}

//function to make in-order traversal to find out the k th smallest element
void traverse(node_t *root,int k){
    if(root == NULL)return;
    traverse(root->left,k);
    count++;
    if(count == k)result = root->data;
    traverse(root->right,k);
}

//function to create node
node_t *createNode(int data){
    node_t *n;

    n = (node_t *)malloc(sizeof(node_t));
    if(n==NULL){
        printf(" No Memory allocated \n");
        exit(1);
    }

    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

//function to print the tree
void printTree(node_t *root){
    if(root == NULL)
        return;
    // inorder print
    printTree(root->left);
    printf(" %d",root->data);
    printTree(root->right);
}


//function to insert node given a data value, doesn't insert when the data value is already present in the tree.
node_t* insert(node_t *root,int data){
    if(root == NULL){
        root = createNode(data);
        return root;
    }
    if(root->data == data)
        printf("Data (%d) already present, Not inserting\n",data);
    else if(root->data > data){
        root->left = insert(root->left,data);
    }else{
        root->right = insert(root->right,data);
    }
    return root;
}

//find and delete a particular data and maintain the BST property
node_t *delete(node_t *root,int data){
    node_t *temp;   //for holding some child branch of a tree temporarily
    node_t *rep;    //for holding the replace node
    int rep_data;   //for holding the replace value
    if(root == NULL)
        return NULL;

    //search for the position of data to be deleted
    if(data < root->data){
        root->left = delete(root->left,data);   //recursively call the function to delete the left branch
    }else if(data > root->data){
        root->right = delete(root->right,data); //recursively call the function to delete the right branch
    }else{
        //perform the deletion

        //if the root node has 0 children
        if((root->left == NULL) && (root->right == NULL)){
            root = NULL; //make an empty tree
        }
        //if the root has a right child
        else if(root->left == NULL){
            temp = root->right;
            root = temp;    //make the right node as root
        }
        //if the root has a left child
        else if(root->right == NULL){
            temp = root->left;
            root = temp; //make the left node as root
        }
        //if root has both the children
        else{
            //replace this node with the maximum node in the left subtree
            rep = root->left;
            while(rep->right!=NULL){
                rep = rep->right;
            }
            rep_data = rep->data;
            root = delete(root,rep_data);   //recursively call the function to delete the root node
            root->data = rep_data;
        }

    }
    return root;

}
