#include "header.h"

int main() {
    index_cognome * surnames;
    index_nome * names;
    int index ;
    int dim = uploadIndex(*&surnames , *&names);
    sort(*&surnames , *&names , dim); // sort the arrays
    DATI * data = new DATI [dim]; // declare the array for all data
    uploadData(*&data); // upload all data from file
    while (true){
        int choose;
        cout << "\tmenu\n1) insert data\n2) get element\n3) show data\n4) show dictionary surnames\n5) show dictionary names\n0) exit\nchoose:_";
        cin >> choose;
        cin.ignore();
        if(!choose){
            cout << "A presto :) \n" ;
            break;
        }
        switch (choose){
            case 1:
                insertAndWrite();
                break;
            case 2:
                index = getElement(surnames,names,dim) ;
                if(index){
                    cout << (data + index)->cognome << "\t" << (data + index)->nome <<  "\t" << (data + index)->citta << "\t" << (data + index)->eta << endl;
                }else{
                    cout << "Key does not exist :( , you can try again :)" << endl;
                }
                break;
            case 3:
                showData(data,dim);
                break;
            case 4:
                dictionarySurnames(surnames,dim);
                break;
            case 5:
                dictionaryNames(names,dim);
                break;
            default:
                cout << "wrong choose :( , try again :)\n" << endl;
                break;
        }
    }

    return 0;
}