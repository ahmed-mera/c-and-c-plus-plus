//
// Created by Ahmed on 22/11/2019.
//

#ifndef DIZIONARIO_HEADER_H
#define DIZIONARIO_HEADER_H
#endif //DIZIONARIO_HEADER_H

//****************************************************************************

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>

#define MAX 20
using namespace std;
//---------------------------------------------------------------------------
/*
 * TODO [ all data of clients ]
 * cognome
 * nome
 * eta
 * citta
 */
typedef struct dati {
    string cognome, citta , nome;
    int eta;
}DATI;
//---------------------------------------------------------------------------
/*
 * TODO [ inert surname and his index in array ]
 */
typedef struct indexCognome {
    string cognome;
    int index;
}index_cognome;
//---------------------------------------------------------------------------
/*
 * TODO [ inert name and his index in array ]
 */
typedef struct indexNome {
    string name;
    int index;
}index_nome;
//---------------------------------------------------------------------------
//insert into array and write on the file
void insertAndWrite (){
    fstream fp; // declare the file name
    DATI * data ; // declare the array
    string dataL; // declare the string for using read the file
    int dim;
    cout << "inserire la dim:_";
    cin >> dim;
    fflush(stdin); // clean the buffer
    data = new DATI [dim]; //create array of all data
    for (int i = 0; i < dim; ++i) {
        cout << "inserire il nome:_";
        getline(cin , data[i].nome); // get name
        fflush(stdin);
        cout << "inserire il cognome:_";
        getline( cin , data[i].cognome); // get surname
        fflush(stdin);
        cout << "inserire la citta:_";
        getline( cin , data[i].citta); // get city
        fflush(stdin);
        cout << "inserire l'eta:_";
        cin >> data[i].eta; //get age
        fflush(stdin);
    }
    fp.open("data.txt", ios::app | ios::in); // open it in mod append and read
    for (int j = 0; j < dim; ++j) {
         // print all data on file
        fp << data[j].cognome << "\t" << data[j].nome << "\t" << data[j].citta<< "\t" << data[j].eta << endl;
    }
    fp.close(); //close it
    /*fp.open("data.csv" , ios::in);
    for (int k = 0;  fp.eof() == 0; ++k) {
        getline(fp,dataL);
        for (int i = 0; i < dataL.size(); ++i) {
            //char(44) == ,
            //char(9) = tab
            if(dataL[i] ==  char(44)){
                dataL[i] = char(9);
            }
        }
        //sscanf(dataL , "%s %s %s %d" , data->cognome , data->nome , data->citta , &data->eta); // ricarico tutti dati
        cout << dataL << endl;
    }*/
};

//-------------------------- ----------------------------------------------------------------
// dictionary of surnames & names

int uploadIndex (index_cognome * &surnames, index_nome * &names ){
    ifstream fp; // declare the file name
    string surname , name  , app;
    int indice = 0 , getLineCount = 0 , i = 0;
    fp.open("data.txt"); // open it in mod append and read
    while(getline(fp,app)){ // eof return [0] if not end file & return [1] when arrive at the end
        getLineCount++;
    }
    fp.close();
    fp.open("data.txt"); // open it in mod append and read
    surnames = (index_cognome*)malloc(sizeof(index_cognome) * (getLineCount)); //allocate the memory
    names = (index_nome*)malloc(sizeof(index_nome) * (getLineCount)); //allocate the memory
    while(getLineCount){ // eof return [0] if not end file & return [1] when arrive at the end
        fp >> surname;
        fp >> name;
        (surnames + i)->cognome = surname;
        (surnames + i)->index = indice;
        (names + i)->name = name;
        (names + i)->index = indice;
        getline(fp , app);
        indice++;
        i++;
        getLineCount--;
    }
    fp.close();

    return indice;
};

//------------------------------------------------------------------------------------------
// dictionary of names
void sort(index_cognome * &surnames, index_nome * &names, int dim){
    string app ;
    int index;
    for (int i = 0; i < dim; ++i) {
        for (int j = i; j < dim; ++j) {
            //for names
            if( (names + i)->name > (names + j)->name){
                app = (names + i)->name;
                index = (names + i)->index;
                (names + i)->name = (names + j)->name;
                (names + i)->index = (surnames + j)->index;
                (names + j)->name = app;
                (names + j)->index = index;
            }
            //for surnames
            if( (surnames + i)->cognome > (surnames + j)->cognome){
                app = (surnames + i)->cognome;
                index = (surnames + i)->index;
                (surnames + i)->cognome = (surnames + j)->cognome;
                (surnames + i)->index = (surnames + j)->index;
                (surnames + j)->cognome = app;
                (surnames + j)->index = index;
            }
        }
    }
};

//------------------------------------------------------------------------------------------
// upload all data
void uploadData (DATI * &data){
    ifstream fp;
    int i = 0;
    fp.open("data.txt");
    while (!fp.eof()){
        fp >> (data + i)->cognome;
        fp >> (data + i)->nome;
        fp >> (data + i)->citta;
        fp >> (data + i)->eta;
        i++;
    }
};

//-------------------------------------------------------
//show data
void showData(DATI * data , int dim){
    cout << "cognome\tnome\tcitta\teta" << endl;
    for (int i = 0; i < dim ; ++i) {
        cout << (data + i)->cognome << "\t" <<  (data + i)->nome << "\t" <<  (data + i)->citta << "\t" <<  (data + i)->eta << endl;
    }
    cout << "\n" << endl;
};
//-------------------------------------------------------
//show dictionary surnames
void dictionarySurnames(index_cognome * surname , int dim){
    cout << " dictionary Surnames  " <<endl;
    cout << "Key\t\tValue" << endl;
    for (int i = 0; i < dim ; ++i) {
        cout << (surname + i)->cognome << "\t===>\t" <<  (surname + i)->index << endl;
    }
    cout << "\n" << endl;
};
//-------------------------------------------------------
//show dictionary names
void dictionaryNames(index_nome * name , int dim){
    cout << " dictionary names " <<endl;
    cout << "Key\t\tValue" << endl;
    for (int i = 0; i < dim ; ++i) {
        cout << (name + i)->name << "\t===>\t" <<  (name + i)->index << endl;
    }
    cout << "\n" << endl;
};
//-------------------------------------------------------
//get element
int  getElement (index_cognome * surname , index_nome * name , int dim){
    string choose;
    int index = 0;
    cout << "Enter the key:_";
    getline(cin , choose);
    fflush(stdin);
    for (int i = 0; i < dim; ++i) {
        if( (surname + i )->cognome == choose){
            index = (surname + i )->index;
            return index;
        }
    }
    // check if index already exist or not
    if(!index){
        for (int j = 0; j < dim ; ++j) {
            if( (name + j )->name == choose){
                index = (name + j )->index;
                return index;
            }
        }
    }

    return index;
}
