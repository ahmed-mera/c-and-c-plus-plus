// Created by Ahmed on 17/11/2019.

#include <iostream>

class createObject {
public:
   // createObject (){ std::cout << "create object" << std::endl;}
    int val;
    void show (createObject * pointer){
        std::cout << "adress of object = " << pointer << " il valore = " << val << std::endl;
    }
};
struct NODO {
    createObject * pointerObject;
    struct NODO * next;
};

typedef struct NODO * nodo;
nodo testa = NULL ;
int count = 0;

void createNodo ();
void show();
