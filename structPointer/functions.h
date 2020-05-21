#include <iostream>
#include <malloc.h>
#include <time.h>
#include <string.h>
#define MAXSIZE 15

using namespace std;

typedef struct { char name[MAXSIZE] , surname[MAXSIZE];  int id; } student;

void carica (student* arr);
void vis (student* arr , int dim);
int cerca (student* arr , int dim);
void elimina (student* arr , int dim );


void carica (student* arr){
      srand(time(NULL));
       int dim , i;
        cout << " inserire la dim dell'array : " ;
        cin >> dim ;
        fflush(stdin);
        arr = (student* )malloc(sizeof(student) * dim);
        for(i = 0; i < dim; i++){
            cout << " inserire il nome dello studente N." << i + 1 << " : ";
            gets((arr + i)-> name) ;

            cout << " inserire il cognome dello studente N." << i + 1 << " : ";
            gets((arr + i)-> surname) ;

             (arr + i)-> id = (rand () % 100 + 1);
        }

        vis(arr , dim);
        cerca(arr , dim);
        elimina(arr , dim);

}

void vis(student* arr , int dim ){
        int i ;
        cout << "Nome " << " \t\t  " << "Cognome  "<< " \t\t " << "Id \n\n" << endl;
        for(i = 0; i < dim; i++){
            cout << i + 1 << " - "<< (arr + i)-> name << " \t\t" << (arr + i)-> surname << " \t\t " << (arr + i)-> id << endl;
    }
}


int cerca (student* arr , int dim) {
        int i , ID ;
        cout << "\n\n\t\t\t\t riceraca studente \n\n\n ID dello Studente   :  " ;
        cin >> ID;
        for(i = 0; i < dim; i++){
            if( ID == (arr + i)->id){
                cout << i + 1 << " - "<< (arr + i)-> name << " \t\t" << (arr + i)-> surname << " \t\t " << (arr + i)-> id << endl;
                return true ;
            }
    }
    cout << "Studente non esistente \n\n" << endl;
    return false;
}

void elimina (student* arr , int dim) {
        int i , j , ID , conta = 0;
        student* tmp;
        cout << "\n\n\t\t\t\t elimina studente \n\n\n ID dello Studente   :  " ;
        cin >> ID;
        tmp = (student*)malloc(sizeof(student) * (dim - 1));

        for(i = 0; i < dim; i++){
            if( ID != (arr + i)->id){
               strcpy( (tmp + j)->name , (arr + i)->name);
               strcpy( (tmp + j)->surname , (arr + i)->surname);
                (tmp + j)->id = (arr + i)->id;
                j = i;
            }else{ conta++; j = i;}
    }
    if (conta != 1)
        cout << "Studente non esistente \n\n" << endl;
    else
        vis(tmp , (dim - 1));
    free(arr);
}



