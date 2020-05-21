#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

typedef struct nodo{
    int valore;
    struct nodo* next;
}LISTA;

typedef LISTA* lista;

int* creaCarica(int dim); //restuisce l'array passando la dim
void creaListe(int dim);
void creaListeOrdinate(int dim);
void visulizza(lista pari , lista dispari);
lista createNodo(lista *testa , int value);

int main()
{
    srand(time(NULL));
    int dim , scelta;
    while (true){
        cout << " \n\t MENU \n\n 1) CREA LISTE & VISULIZZA \n 2) CREA LISTE ORDINATE & VISULIZZA \n 3) CREA E CARICA ARRAY DINAMECO \n 0) USCITA \n\n SCEGLI :_" ;
        cin >> scelta;
          if(scelta){
            cout << "\n\t INSERIRE LA DIMMENSIONE :_";
            cin >> dim;
          }
        system("cls");// clear screen
        switch (scelta){
        case 1:
            cout << " \t\t\t LISTE CON NUMERI CASUALI \n " << endl;
            creaListe(dim);
            break;
        case 2:
            cout << " \t\t\t LISTE ORDINATE \n " << endl;
            creaListeOrdinate(dim);
            break;
        case 3:
            creaCarica(dim);
            cout << "\t L'ARRAY E' STATA CREATA E CARICATA CON NUMERI CASUALI CON SUCCESSO ;) \n "<<endl;
            break;
        case 0:
            cout << "\n\t\t\t A PRESTO ;) \n\n" <<endl;
            exit(0);
            break;
        default:
            cout << "\n \t\t\t INSERIMENTO NON E' CORRETTO, RIPORVA :( \n\n" << endl;
            break;
        }
    }

    return 0;
}


lista createNodo(lista* testa , int value){
    lista nuovo = new nodo;
    nuovo->valore = value;
    if(*testa == NULL){
        nuovo->next = NULL;
        *testa = nuovo;
    }else{
        lista scorri = *testa;
        while(scorri->next != NULL){
            scorri = scorri->next;
        }
        scorri->next = nuovo;
        nuovo->next = NULL;
    }
    return nuovo;
}


int* creaCarica(int dim){
    int *arr = (int*) malloc(sizeof(int) * dim); //alloco la dim
    int i ;
    for(i = 0; i < dim; i++){
        *(arr + i) = (rand() % 50 ) + 1;
    }
    return arr;
}

void creaListe(int dim){
    int  i;
    int *arr = creaCarica(dim);
    lista LISTAPARI = NULL;
    lista LISTADISPARI = NULL;

    for(i = 0; i < dim; i += 1){
        lista nuovo; //CREATE NEW NODO
        if(*(arr + i) % 2 == 0){
             nuovo = createNodo(&LISTAPARI , *(arr + i));
        }else{
             nuovo = createNodo(&LISTADISPARI , *(arr + i));
         }
    }
    visulizza(LISTAPARI , LISTADISPARI);
}

void creaListeOrdinate(int dim){
       int i , j , app;
    int *arr = creaCarica(dim);
    lista LISTAPARI = NULL;
    lista LISTADISPARI = NULL;

    //ordina l'array
    for(i = 0; i < dim ; i++){
        for(j = i; j < dim; j++){
            if(*(arr + i) > *(arr + j)){
                app = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = app;
            }
        }
    }

    for(i = 0; i < dim; i++){
        lista nuovo;
        if(*(arr + i) % 2 == 0){
             nuovo = createNodo(&LISTAPARI , *(arr + i));
        }else{
             nuovo = createNodo(&LISTADISPARI , *(arr + i));
         }
    }
    visulizza(LISTAPARI , LISTADISPARI);
}



void visulizza(lista pari , lista dispari){
    lista scorriPari = pari;
    lista scorriDispari = dispari;
    cout << "\n NUMERI PARI : ";
    while(scorriPari != NULL){
            cout << scorriPari->valore << "\t";
            scorriPari = scorriPari->next;
    }
    cout << "\n NUMERI DISPARI : ";
    while(scorriDispari != NULL){
            cout << scorriDispari->valore << "\t";
             scorriDispari = scorriDispari->next;
    }
    cout << "\n";
}


