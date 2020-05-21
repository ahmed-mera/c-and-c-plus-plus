//
// Created by Ahmed on 20/02/2020.
//

#ifndef ESERCIZI_ALBERI_BINARI_TREE_H
#define ESERCIZI_ALBERI_BINARI_TREE_H


#include <iostream>
#include <fstream>
#include <list>
using namespace std;

class tree{

public:
    fstream file ;
    fstream listFile ;
    int countLeaves , countNodes , sumLeaves , sumLevel, level;
//    float avg; // for average
//    int sumLevel; // sum all leaves

    //for nodes of tree
    struct node {
        int value , level;
        struct node * left , * right ;
        list <int> list;
    };

    typedef struct node * NODE; // new type

    NODE ROOT; // declaration of root

    tree(); // my construct

     NODE creatNode(int); //create node
     list <int> createList(list <int> , int); // create list for duplicated
     NODE insert(NODE , int);
    /*!  methods of through the tree  */
    void inorder(NODE); // SRD => LEFT - RIGHT - ROOT
    void preorder(NODE); //  RSD  => ROOT - LEFT - RIGHT
    void postorder(NODE); // SDR => LEFT - RIGHT - ROOT
    int search(NODE , int); // for searching an element
    void saveTreeToFile(NODE);
    void saveListToFile(NODE);
    void readTreeFromFile(NODE &);
    void COUNTLEAVES(NODE); // counter leaves
    void showLists(NODE); // show lists if exist
    float averageLeaves(); // get average
    void assignedLvl(NODE); // get level
    int sumValueLevel(NODE , int);

};


#endif //ESERCIZI_ALBERI_BINARI_TREE_H
