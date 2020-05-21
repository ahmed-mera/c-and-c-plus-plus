#include "header.h"

/* construct */
LISTE :: LISTE (){
    NUOVO = NULL;
    HEAD = NULL;
}

/* all functions */

void LISTE :: createNodo (){
  NUOVO = new nodo; //create new nodo
  cout << "INSERIRE IL NOME :_ ";
    gets(NUOVO->nome);
    fflush(stdin);
  cout << "INSERIRE IL COGNOME :_ ";
    gets(NUOVO->cognome);
    fflush(stdin);

  if(HEAD == NULL){
    NUOVO->NEXT = NULL;
    HEAD = NUOVO; // assegn indress for head
  }else{
      nodo* testa = HEAD;
    while(testa->NEXT != NULL){
        testa = testa->NEXT;
    }
    testa->NEXT = NUOVO;
    NUOVO->NEXT = NULL;

  }
  cout << "\n";
  //cout << NUOVO <<endl;
  //cout << HEAD <<endl;

}

void LISTE :: ordinaNomi (){
    nodo* testa = HEAD;
    nodo* scorri = NULL ;
    char nome [MAX_SIZE] , cognome [MAX_SIZE];
    while(testa != NULL){
         scorri = HEAD;
            while(scorri != NULL){
                 if (strcmp(testa->nome , scorri->nome ) < 0 && (scorri->NEXT != NULL)){

                        strcpy(nome , scorri->nome);
                        strcpy(cognome , scorri->cognome);
                       // pre->NEXT = testa->NEXT;


                        strcpy(scorri->nome , testa->nome);
                        strcpy(scorri->cognome , testa->cognome);

                        strcpy(testa->nome , nome);
                        strcpy(testa->cognome ,cognome);


                        /*pre = scorri;
                        cout << pre << endl;
                        pre->NEXT->NEXT  = pre->NEXT ;
                        cout << pre->NEXT << endl;*/

                    }
                    scorri = scorri->NEXT;
                }

        testa = testa->NEXT;
        cout << "testa =>" << testa << endl;
    }
   delete(scorri);
}

void LISTE :: ordinaCognomi (){
    nodo* testa = HEAD;
    nodo* scorri = NULL ;
    nodo* app;
    char nome [MAX_SIZE] , cognome [MAX_SIZE];
    while(testa != NULL){
         scorri = HEAD;
            while(scorri != NULL){
                 if (strcmp(testa->cognome , scorri->cognome ) < 0 && (scorri->NEXT != NULL)){

                        strcpy(nome , scorri->nome);
                        strcpy(cognome , scorri->cognome);
                        //app = scorri->NEXT;


                        strcpy(scorri->nome , testa->nome);
                        strcpy(scorri->cognome , testa->cognome);
                        //scorri->NEXT = testa->NEXT;

                        strcpy(testa->nome , nome);
                        strcpy(testa->cognome ,cognome);
                        //testa->NEXT = app;

                    }
                    scorri = scorri->NEXT;
                }

        testa = testa->NEXT;
       // cout << "testa =>" << testa << endl;
    }
   delete(scorri);
}

void LISTE :: show (){
    nodo* testa = HEAD;
    if(testa == NULL){
        cout << "LISTA VUOTA " << endl;
    }else{
        while(testa != NULL){
            cout << testa << "\t "<< testa->nome << "\t " << testa->cognome << endl;
            testa = testa->NEXT;
        }
    }
}
