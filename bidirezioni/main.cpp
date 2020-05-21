#include "header.h"

int main()
{
    NODO RIGHT = NULL;
    NODO LEFT = NULL;
    int i;

    for(i = 0; i < 10; i++){
        createNodo(i+1 , *&RIGHT , *&LEFT );
    }

    show(RIGHT , LEFT);

    return 0;
}
