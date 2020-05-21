#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include "../esercizi_alberi_binari/tree.h" // albero binario

using namespace std;
/*********************************************** start prototype ************************************************/

/*
 * arrayNum( string )
 * prende la stringa come un parametro.
 * le viene passato per valore.
 * restiuisce un array di interi
 *
 * */
vector <int> arrayNum(string );

/*
 * listNum( string )
 * prende la stringa come un parametro.
 * le viene passato per valore.
 * restiuisce una lista
 *
 * */
list <int> listNum(string );

/*
 * StackNum( string )
 * prende la stringa come un parametro.
 * le viene passato per valore.
 * restiuisce una stack
 *
 * */
stack <int> stackNum(string );


/*
 * showArrayVector(vector <int> )
 * prende array come un parametro.
 * le viene passato per valore.
 * visulizza tutti gli elementi
 *
 * */
void showArrayVector(vector <int> );

/*
 * showList(list <int> )
 * prende list come un parametro.
 * le viene passato per valore.
 * visulizza tutti gli elementi
 *
 * */
void showList(list <int> );

/*
 * showStack(stack <int> )
 * prende list come un parametro.
 * le viene passato per valore.
 * visulizza tutti gli elementi
 *
 * */
void showStack(stack <int> );
/*********************************************** end prototype ************************************************/

/*********************************************** start main () ************************************************/

int main() {
    tree TREE; // creazione di un oggetto che gestisce l'albero binario di ricerca

    string operation; // dichirazione della variabile operazione che inserira' l'utente

    cout << "Enter your operation you want to do:_";

    cin >> operation; // prelavre l'operazione

    cin.ignore(); // pulizie del buffer

    /******************************************* start 1st task ******************************************/
    vector <int> operationVector = arrayNum(operation); // assignment and call function arrayNum()
    showArrayVector(operationVector); // call function show()
    /******************************************* end 1st task ******************************************/


    /******************************************* start 2st task ******************************************/
    list <int> operationList = listNum(operation); // assignment and call function listNum()
    showList(operationList); // call function show()
    /******************************************* end 2st task ******************************************/


    /******************************************* start 3st task ******************************************/
    stack <int> operationStack = stackNum(operation); // assignment and call function stackNum()
    showStack(operationStack); // call function show()
    /******************************************* end 3st task ******************************************/


    /******************************************* start 4st task ******************************************/
    for (int i : operationVector)
        TREE.ROOT = TREE.insert(TREE.ROOT , i ); // creazione di node

    cout << "albero : " ;
    TREE.inorder(TREE.ROOT); // visulizza l'albero inorder
    /******************************************* end 4st task ******************************************/

    return   0;
}
/*********************************************** end main () ************************************************/

/*********************************************** start body functions () ************************************************/
vector <int> arrayNum(string operation){
    int checkCondition ; // per sapere se esisteno di numeri o no
    string newOperation; // per salvare i numeri come stringa
    vector <int> arrayNumbers; // per salvare i numeri dentro un array
    for (int i = 0; i < operation.length() ; ++i) {
        checkCondition = 1; // rest value
        newOperation = "";// rest value
        for (; checkCondition == 1;) { // check condition
            if(operation[i] >= '0' && operation[i]  <= '9'){
                newOperation += operation[i]; // assign value
                ++i; // increment i
            }else{
                if ( ! newOperation.empty() ) // check condition
                    arrayNumbers.push_back(stoi(newOperation)); // put number in array

                checkCondition = 0; // rest value
            }
        }
    }
    return arrayNumbers; // return array
}

/*********************************************** ****************** ************************************************/

list <int> listNum(string operation){
    int checkCondition ; // per sapere se esisteno di numeri o no
    string newOperation; // per salvare i numeri come stringa
    list <int> arrayNumbers; // per salvare i numeri dentro una lista
    for (int i = 0; i < operation.length() ; ++i) {
        checkCondition = 1; // rest value
        newOperation = "";// rest value
        for (; checkCondition == 1;) { // check condition
            if(operation[i] >= '0' && operation[i]  <= '9'){
                newOperation += operation[i]; // assign value
                ++i; // increment i
            }else{
                if ( ! newOperation.empty() ) // check condition
                    arrayNumbers.push_back(stoi(newOperation)); // put number in array

                checkCondition = 0; // rest value
            }
        }
    }
    return arrayNumbers; // return list
}

/*********************************************** ****************** ************************************************/

stack <int> stackNum(string operation){
    int checkCondition ; // per sapere se esisteno di numeri o no
    string newOperation; // per salvare i numeri come stringa
    stack <int> arrayNumbers; // per salvare i numeri dentro un stack
    for (int i = 0; i < operation.length() ; ++i) {
        checkCondition = 1; // rest value
        newOperation = "";// rest value
        for (; checkCondition == 1;) { // check condition
            if(operation[i] >= '0' && operation[i]  <= '9'){
                newOperation += operation[i]; // assign value
                ++i; // increment i
            }else{
                if ( ! newOperation.empty() ) // check condition
                    arrayNumbers.push(stoi(newOperation)); // put number in array

                checkCondition = 0; // rest value
            }
        }
    }
    return arrayNumbers; // return list
}

/*********************************************** ****************** ************************************************/

void showArrayVector(vector <int> new_operation ){
    if(new_operation.empty()){
        cout << " array vuoto :(" << endl;
        return;
    }

    cout << "Vector : ";
    for (auto l : new_operation)
        cout << l << " ";

    cout << endl;
}

/*********************************************** ****************** ************************************************/

void showList(list <int> new_operation ){
    if(new_operation.empty()){
        cout << " array vuoto :(" << endl;
        return;
    }

    cout << "List : ";
    for (auto l : new_operation)
        cout << l << " ";

    cout << endl;
}

/*********************************************** ****************** ************************************************/

void showStack(stack <int> new_operation ){
    if(new_operation.empty()){
        cout << " array vuoto :(" << endl;
        return;
    }

    cout << "stack : ";
    while (! new_operation.empty()){
        cout << new_operation.top() << " ";
        new_operation.pop(); // tolgo l'ultimo elemento
    }

    cout << endl;
}

/*********************************************** end body functions () ************************************************/
