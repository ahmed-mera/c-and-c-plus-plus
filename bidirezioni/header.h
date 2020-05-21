#include <iostream>

using namespace std;

struct nodo{
    int valore;
    struct nodo* next;
    struct nodo* prev;
};

typedef struct nodo* NODO;

void createNodo (int valore , NODO &right , NODO &left);
void show (NODO right , NODO left);
