//
// Created by Ahmed on 28/05/2020.
//

#ifndef BULLMAN_FORD_HEADER_H
#define BULLMAN_FORD_HEADER_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vector"
#include <cstring>
using namespace std;
typedef struct finallyStruct{
    char  nameNode;
    int distanceToNextNode;
}ROUTE;

typedef struct node{
    char  nameNode;
    int rightValue, leftValue, distanceToNextNode;
    struct node * next;
}NODE;

const char nodesNames [] = {'A', 'B', 'C', 'D', 'E', 'F'};

NODE * createNode(char  , int );
ROUTE * createNode(string  , char );
void print(const vector<NODE*>& );
void print(const vector<ROUTE*>& );
void print(NODE * head);
void fullStructNodes (vector<NODE*>* );
void calcRoute(vector<NODE *> );
void linking(vector<NODE*>& nodes, NODE *& head);
void linkingNode(NODE* , NODE*&);
void Shuffle(vector<NODE*> & );
void CALC(vector<NODE*> , vector<ROUTE *> &);

#endif //BULLMAN_FORD_HEADER_H
