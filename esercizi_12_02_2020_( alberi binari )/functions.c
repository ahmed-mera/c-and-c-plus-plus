//
// Created by Ahmed on 14/02/2020.
//

#include "header.h"

/*! function for creating node and return the address memory */
NODE createNode(int value) {
    NODE newNode = (NODE)malloc(sizeof(struct node)); // allocate space for my node
    newNode->data = value; // assignment value
    newNode->left = NULL; // assignment value pointer left
    newNode->right = NULL; // assignment value pointer right
    return newNode; // return my address memory
}

NODE insert(NODE root, int data){
    if (root == NULL) return createNode(data);
    if (data < root->data) root->left  = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}


int search(NODE root , int number){
    if (root == NULL) return (int) NULL;
    if (number == root->data) return root->data;
    if (number < root->data) return search(root->left, number);
    if (number > root->data) return search(root->right, number);
}

void inorder(NODE root) {
    if(root == NULL) return;
    inorder(root->left);
    printf("\t%d", root->data);
    inorder(root->right);
}

void preorder(NODE root) {
    if(root == NULL) return;
    printf("\t%d", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(NODE root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("\t%d", root->data);
}

NODE readFile(NODE root){
    int number;
    FILE* fp ;
    fp = fopen("tree.txt", "r");
    while (!feof(fp)){
        fscanf(fp,"%d",&number);
        root = insert(root, number);
    }
    return root;
}