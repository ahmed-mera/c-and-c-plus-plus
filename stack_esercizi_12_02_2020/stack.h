//
// Created by Ahmed on 14/02/2020.
//

#ifndef STACK_ESERCIZI_12_02_2020_STACK_H
#define STACK_ESERCIZI_12_02_2020_STACK_H

#endif //STACK_ESERCIZI_12_02_2020_STACK_H

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#define ERR -1
#define OK 0

typedef int stack_type;

static stack_type *st;
static unsigned int numel = 0, max;

int initSTACK(unsigned int nmax);
unsigned int isSTACKempty(void);
unsigned int isSTACKfull(void);
stack_type popSTACK(void);
void pushSTACK(stack_type a);
void destroySTACK(void);
void show();
