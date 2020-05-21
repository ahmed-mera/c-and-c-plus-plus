// ALBERI  alberi - Visite INORDER - PREORDER - POSTORDER

#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
struct RTnodo {
    int key;
    RTnodo *left, *right;
};
typedef RTnodo* Tnodo;
Tnodo Insert(int, Tnodo, Tnodo);
Tnodo InsertSort(int , Tnodo );
void CreaAlbero(Tnodo& );
void InOrder(Tnodo);
void Preorder(Tnodo);
void Postorder(Tnodo);
void writeTree(Tnodo , int );

int main ()  {
    Tnodo A,A1;
    int Num;
    RTnodo Nodo;
    CreaAlbero(A);
    writeTree(A,1);cout<<endl;
    cout<<"\n INORDER "<<endl;
    InOrder( A) ;cout<<endl;
    cout<<"\n PREORDER "<<endl;
    Preorder(A) ;cout<<endl;
    cout<<"\n POSTORDER "<<endl;
    Postorder(A) ;cout<<endl<<endl;
    system("pause");
}

// DEFINIZIONI

Tnodo Insert(int key1, Tnodo ASX, Tnodo ADX) {
//PER INSERIRE UNA FOGLIA SI CHIAMA CON Insert(Numero,NULL,NULL)
    Tnodo A2;
    A2= new RTnodo;
    A2->key=key1;
    A2->left=ASX;
    A2->right=ADX;
    return A2;
}
Tnodo InsertSort(int key1, Tnodo A)  {
    if (A==NULL)
        return Insert(key1,NULL,NULL);
    else if (A->key > key1)
        return Insert(A->key,InsertSort(key1,A->left),A->right);
    else if (A->key < key1)
        return Insert(A->key,A->left,InsertSort(key1,A->right));
    else
        return A ;
}

void CreaAlbero(Tnodo& A)  {
    int Num;
    string NomeIn, NomeOut;
    NomeIn="TREE1.txt";
    cout<<"\n CREO L'ALBERO A PARTIRE DAL FILE "<<NomeIn<<endl<<endl;
    A=NULL;

    ifstream filista;
    ofstream outlista;

    filista.open(NomeIn.c_str());
    if (!filista)
    {
        cerr<<"Non si puo' aprire il file. \n costruire un file di nome TREE1.txt contenete la lista delle chiavi "<<endl;
        system("pause");
    }
    filista>>Num;
    while (!filista.eof()) {
        A = InsertSort(Num,A);
        cout<<"Ho inserito la chiave ="<<Num<<endl;
        filista>>Num;
    }
}
void writeTree(Tnodo A, int i)
{
    if (A!=NULL)
    {
        writeTree(A->right,i+1);
        for (int j=1;j<=i;j++)
            cout<<"  ";
        cout<<A->key;
        cout<<endl;
        writeTree(A->left,i+1);
    }
}

void InOrder(Tnodo A)  {
    if (A!=NULL)  {
        InOrder(A->left);
        cout<<A->key<<" ";
        InOrder(A->right);
    }
    else
        cout<<" ";
}

void Preorder(Tnodo A)  {
    if (A!=NULL)  {
        cout<<A->key<<" ";
        Preorder(A->left);
        Preorder(A->right);
    }
    else
        cout<<" ";
}

void Postorder(Tnodo A)  {
    if (A!=NULL)  {
        Postorder(A->left);
        Postorder(A->right);
        cout<<A->key<<" ";
    }
    else
        cout<<" ";
}
