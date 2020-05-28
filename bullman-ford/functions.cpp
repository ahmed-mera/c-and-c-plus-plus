//
// Created by Ahmed on 28/05/2020.
//

#include "header.h"

NODE * createNode(char name , int valueR, int valueL){
    NODE * newNode = new NODE ;
    newNode->nameNode = name;
    newNode->rightValue = valueR;
    newNode->leftValue = valueL;
    newNode->distanceToNextNode = 0;
    newNode->next = nullptr;
    return newNode;
}

ROUTE * createNode(int route , char name){
    ROUTE * newNode = new ROUTE ;
    newNode->distanceToNextNode = route;
    newNode->nameNode = name;
    return newNode;
}

void print(const vector<ROUTE *>& nodes ){

    for (auto node : nodes)
        cout << node->nameNode << "\t";
    cout << endl;

    for (auto node : nodes)
        cout << node->distanceToNextNode << "\t";
    cout << endl;

}

void print(const vector<NODE *>& nodes ){

    cout <<  "Name \t Right \t left \t Route" << endl;
    for (auto node : nodes)
        cout << node->nameNode << "\t" << node->rightValue << "\t" << node->leftValue << "\t" << node->distanceToNextNode << endl;

}

void print(NODE * head){
    cout <<  "Name \t Right \t left \t next" << endl;
    NODE * tmp = head;
    while(tmp != nullptr){
        cout << tmp->nameNode << "\t" << tmp->rightValue << "\t" << tmp->leftValue << "\t";
        if( tmp->next)
            cout << tmp->next->nameNode << endl;
        else
            cout << "null" << endl;

        tmp = tmp->next;
    }

}

void fullStructNodes (vector<NODE*> *structNodes){

    for (char nodesName : nodesNames)
        (*structNodes).push_back(createNode(nodesName, (rand() % 10 + 1), (rand() % 10 + 1) ) ) ;

}

//void linkingNode(NODE* node, NODE *& head) {
//    if(head == nullptr) {
//        head = node;
//    }else{
//        node->next = head;
//        head = node;
//    }
//}

void linking(vector<NODE*>& nodes, NODE *& head){
    Shuffle(nodes);
    for (auto node : nodes) {
        if(head == nullptr) {
            head = node;
        }else{
            node->next = head;
            head = node;
        }
    }
}

void Shuffle(vector<NODE*> & v) {
    int size = v.size();
    for (int i = 0; i < size - 1; i++) {
        int j = i + rand() % (size - i);
        swap(v[i], v[j]);
    }
}
void CALC(vector<NODE*> nodes, vector<ROUTE *> & routes){
    int value = 0;
    for (int i = 0; i < nodes.size() ; i++) {
        value += nodes[i]->rightValue;
        if(!i){
            routes.push_back(createNode( i, nodes[i]->nameNode));
        } else{
            routes.push_back(createNode( value, nodes[i]->nameNode));
        }
    }
}

