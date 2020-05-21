#include "stack.h"

int main( )
{
    unsigned int scelta = 1, element , dim;
    printf("inserire la dim dello stack:_");
    scanf("%d",&dim);
     if(initSTACK(dim) != ERR){
         printf("\t\t\t\tspazio allocato con successo ;)\n\n\n");
     } else{
         printf("spazio NON allocato :(\n");
         exit(0);
     }

    while(scelta) {
        printf("1) Inserisci nuovo elemento \n2) Estrai Elemento \n3) Svuota e Visualizza Stack \n4) Visualizza Stack senza eliminare gli elementi presenti \n5) Visualizza il numero di elementi inseriti \n6) Visualizza il numero di elementi liberi \n0) Uscita \n");
        printf("scegli:_");
        scanf("%d", &scelta);
        switch (scelta) {
            case 0:
                printf("a presto ;) \n");
                exit(0);
            case 1:
                system("cls");
                printf("inserire un nuovo elemento:_");
                scanf("%d", &element);
                pushSTACK(element);
                printf("elemento inserito con successo ;) \n");
                break;
            case 2:
                system("cls");
                popSTACK();
                printf("elemento estratto con successo ;) \n");
                break;
            case 3:
                system("cls");
                printf("svuotamento in corso.........");
                destroySTACK(); // delete the stack
                sleep(1);
                system("cls");
                initSTACK(max); // allocate space for a new stack
                show();
                break;
            case 4:
                system("cls");
                show();
                break;
            case 5:
                system("cls");
                printf("elementi inseriti = %d", numel);
                break;
            case 6:
                system("cls");
                printf("elementi libri = %d", max - numel);
                break;
            default:
                system("cls");
                printf("scelta sbagliata, riprovaci :( \n");
                break;
        }
    }
    return 0;
}
