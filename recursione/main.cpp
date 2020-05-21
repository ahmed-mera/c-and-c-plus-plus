#include <iostream>
using namespace std;

int ricerca ( int arr [] , int dim , int eleRicerca );

int main() {
    int arr[6] = {1 , 2 , 3 , 4 , 5 , 6};
    int mid , left = 0 , right = -1 , search;
    bool var = true;
    search = 7;
    mid = 6 / 2;
    /**
     * la funzione ricursione
     *
     **/

    ricerca(arr , 6 , search); // call function

    /***********************************************************************************************************************/

    /**
     * iterazione
     *
     **/
    while(var){
        left = mid - left;
        right = mid + right ;
        if(search == arr[mid]){
            cout << "ecco il numero = " << mid <<  endl;
            var = false;
        }else if (search < arr[mid]){
            mid = left / 2;
        }else if (left == right){
            cout << " ele non esiste" <<endl;
            var = false;
        }else {
            mid = right / 2;
        }
    }
    /***********************************************************************************************************************/

    return 0;
}

int ricerca ( int arr [] , int dim , int eleRicerca ){
    int mid = dim / 2;
    if(arr[mid] == eleRicerca){
        cout << "elemento trovato in posizione :" << mid <<endl;
        return 1;
    }else if(arr[mid] < eleRicerca){
        mid = dim + mid;
        ricerca(arr , mid , eleRicerca);
    }else if (mid > eleRicerca){
        cout << "elemento non trovato :(" <<endl;
        return 0;
    } else{
        mid = dim - mid;
        ricerca(arr , mid , eleRicerca);
    }
    return 1;
}
