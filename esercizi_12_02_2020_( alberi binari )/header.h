//
// Created by Ahmed on 14/02/2020.
//

#ifndef ESERCIZI_12_02_2020___ALBERI_BINARI___HEADER_H
#define ESERCIZI_12_02_2020___ALBERI_BINARI___HEADER_H

#endif //ESERCIZI_12_02_2020___ALBERI_BINARI___HEADER_H

#include<stdio.h>
#include<stdlib.h>
/* declare my struct */
struct node {
    int data; // for data
    struct node* left; // for pointer left
    struct node* right; // for pointer right
};

typedef struct node* NODE; // declare a new type

NODE createNode(int value);
NODE insert(NODE root, int data);
int search(NODE root, int number);
void inorder(NODE root);
void preorder(NODE root);
void postorder(NODE root);
NODE readFile(NODE root);