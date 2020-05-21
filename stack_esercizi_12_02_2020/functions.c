//
// Created by Ahmed on 14/02/2020.
//

#include "stack.h"
/* inizializzazione */
int initSTACK(unsigned int nmax){
    max=nmax;
    return  ( st = (stack_type *)malloc(sizeof(stack_type)*nmax) ) == NULL ? ERR : OK;
} //Provare a Gestire con Eccezioni  TODO ( NON POSSO PEECHE' QUESTO E' IL C NON IL C++ )

/* controlla se e' vuoto */
unsigned int isSTACKempty(void) {
    return ! numel;
}
/* controlla se e' pieno */
unsigned int isSTACKfull(void) {
    return numel==max;
}

/* preleva un elemento dallo stack */
stack_type popSTACK(void){
    if(!isSTACKempty()){
        numel--;
        return st[numel];
    }else{
        printf("stack vuoto :(\n");
        return ERR;
    }
}
/* mette un elemento in cima allo stack */
void pushSTACK(stack_type a){
    if(isSTACKfull()){
        printf("stack pieno :(\n");
    }else{
        st[numel] = a;
        numel++;
    }

}

void destroySTACK(void){
    free(st);
}

void show(){
    if(isSTACKempty()){
        printf("stack vuoto :(\n");
    } else{
        printf("stack = ");
        for (int i = 0; i < numel; ++i) {
            if(i != ( numel - 1) )
                printf("[ %d ]==>",st[i]);
            else
                printf("[ %d ]\n",st[i]);
        }
    }
}