#include <iostream>
#include <string.h>
#define MAX_SIZE 20
using namespace std;

class LISTA {
public:
    struct nodo{
        char nome [MAX_SIZE] , cognome[MAX_SIZE]; // per il nome el il cognome
        struct nodo* Pnome; // puntatore per il  nome
        struct nodo* Pcognome; //puntatore per il cognome
    };

    typedef struct nodo* lista; // decrazione di nuovo tipo

    lista testaNome; //decherazione di un puntatore testa nome
    lista testaCognome; //decherazione di un puntatore testa cognome
    lista nuovo; //nuovo nodo

    LISTA (){ // construct
        testaNome = NULL;
        testaCognome = NULL;
        nuovo = NULL;
    }
    //---------------------------------------------------------------------------------------------------------------
    //functions
    void createNodo () {
        nuovo = new nodo;
        cout << "inserire il nome :_ ";
        gets(nuovo->nome);
        fflush(stdin);
        cout << "inserire il cognome :_ ";
        gets(nuovo->cognome);
        fflush(stdin);
        if(testaNome == NULL){
            testaNome = nuovo;
            nuovo->Pnome = NULL;
        }else{
            lista scorri = testaNome;
            while (scorri->Pnome != NULL){ scorri = scorri->Pnome;}
            scorri->Pnome = nuovo;
            nuovo->Pnome = NULL;
            //ordina_nome();
        }

        if(testaCognome == NULL){
            testaCognome = nuovo;
            nuovo->Pcognome = NULL;
        }else{
             lista scorri = testaCognome;
            while (scorri->Pcognome != NULL){ scorri = scorri->Pcognome;}
            scorri->Pcognome = nuovo;
            nuovo->Pcognome = NULL;
           // ordina_cognome();
        }
    };
    //---------------------------------------------------------------------------------------------------------------

    void show_nome() {
        if(testaNome == NULL){
            cout << "\n\n \t\t LISTA VUOTA :( \n" << endl;
        }else{
            lista scorri = testaNome;
            while (scorri != NULL){
                cout << "iam here" << endl;

                cout << scorri << "\t\t" << scorri->nome << "\t" << scorri->cognome << endl;

                scorri = scorri->Pnome;
            }
        }
    };
   //---------------------------------------------------------------------------------------------------------------

    void show_cognome() {
        if(testaCognome == NULL){
            cout << "\n\n \t\t LISTA VUOTA :( \n" << endl;
        }else{
            lista scorri = testaCognome;
            while (scorri != NULL){
                    cout << "iam here" << endl;
                cout << scorri << "\t\t" << scorri->nome << "\t" << scorri->cognome << endl;
                scorri = scorri->Pcognome;
            }
        }
    };
    //---------------------------------------------------------------------------------------------------------------

    void ordina_nome(){
        if(testaNome == NULL){
            cout << "\n\n \t\t LISTA VUOTA :( \n" << endl;
        }else{
            lista scorri = testaNome;
            lista scorri_2;
            lista app ;
            while (scorri != NULL){
                scorri_2 = testaNome;
                while (scorri->Pnome != NULL){
                    app = scorri_2;
                    scorri_2 = scorri_2->Pnome;
                    if(strcmp(scorri->nome, scorri_2->nome) < 0) {
                        scorri_2->Pnome = scorri;
                        scorri->Pnome = app;
                    }
                }
                scorri = scorri->Pnome;
            }
        }
    };
    //---------------------------------------------------------------------------------------------------------------

    void ordina_cognome() {};


};

