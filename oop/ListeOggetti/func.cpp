// Created by Ahmed on 17/11/2019.

#include "header.h"
void createNodo (createObject object){
    nodo nuovo = new NODO; //create new nodo
    //createObject object; //create a new object
    nuovo->pointerObject = &object; //assegn his address
    //nuovo->pointerObject->val = count + 1; //assegn value
    //nuovo->pointerObject->show(&object); //call function
    nuovo->next = NULL;
    //std::cout << "Nouvo = " << nuovo << std::endl;
    if (testa == NULL ) { testa = nuovo; }
    else {
        nodo app = testa ;
        while (app->next != NULL){ app = app->next;}
        app->next = nuovo;
    }
    count++;
}

void show (){
    if (testa == NULL ) { std :: cout << "lista Vouta :( " ;  exit(0) ;}
    else {
        nodo app = testa ;
        while (app != NULL){
            std :: cout << app->pointerObject << "\t " << app->next << std::endl;
            app = app->next;
        }
    }
}