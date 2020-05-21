#include <iostream>
#include <cctype>
using namespace std;

typedef struct nodo {
    char c;
    struct nodo * next;
} NODO;

NODO * VOCALI = nullptr;
NODO * CONSONATI = nullptr;

int h(int c);
string crittografia(string stringa );
int gestire (string stringa );
void show(NODO * testa);

int main() {
    string stringa_1 = "ahmed" , stringa_2 = crittografia(stringa_1);
    cout << "------------------------------ crittografia -----------------------------------"<<endl;
    cout << stringa_2 << endl;

    int vocali = gestire(stringa_1);
    cout << "------------------------------ numeri -----------------------------------"<<endl;
    cout << "total  = " << stringa_1.length() << endl;
    cout << "vocali  = " << vocali << endl;
    cout << "consonati  = " << ( stringa_1.length() -vocali) << endl;
    cout << "------------------------------ vocali -----------------------------------"<<endl;
    show(VOCALI);
    cout << "------------------------------ consonanti --------------------------------"<<endl;
    show(CONSONATI);
    cout << "-------------------------------------------------------------------------"<<endl;
    return 0;
}

int h(int c){ return (c + 3) > 90 ? ((c + 3)  - 90) + 64 : (c + 3); }

string crittografia(string stringa){
    string stringa_convertita;
    for (int i = 0; i < stringa.length(); ++i)
       stringa_convertita += h(toupper(stringa[i]));
    return stringa_convertita;
}



int gestire(string stringa){
    int vocali = 0, count;
    string voc = "aeoui";
    for (int i = 0; i < stringa.length() ; ++i) {
        count = 0;
        NODO* nuovo = new NODO;
        for (int j = 0; j < voc.length(); ++j) {
            if (toupper(voc[j]) == toupper(stringa[i])){
                vocali++;
                count++;
                nuovo->c = stringa[i];
                if(VOCALI == NULL){
                    VOCALI = nuovo;
                } else{
                    NODO * tmp = VOCALI;
                    while (tmp->next){
                        tmp = tmp->next;
                    }
                    tmp->next = nuovo;
                }
            }
        }
        if (!count){
            nuovo->c = stringa[i];
            if(CONSONATI == NULL){
                CONSONATI = nuovo;
            } else{
                NODO * tmp = CONSONATI;
                while (tmp->next){
                    tmp = tmp->next;
                }
                tmp->next = nuovo;
            }
        }
        nuovo->next = nullptr;
    }
    return vocali;
}

void show (NODO * testa){
    NODO * tmp = testa;
    while (tmp){
        cout << tmp->c << endl;
        tmp = tmp->next;
    }
}