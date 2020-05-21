#include <iostream>
#include <string.h>
#include <typeinfo>

template <class t> t max(t a , t b){ return a > b ? a : b; }
template <class t> t min ( t a , t b){ return a < b ? a : b; }
template <class t> t sort(t array[] , int dim );


int main() {
    //----------------------------------------------------------
    std::cout << "il Massimo :" << std::endl;
    std::cout << max(5, 10)<< std::endl; //int
    std::cout << max(2.5, 2.7)<< std::endl; //float
    std::cout << max("ahmed" , "Mera")<< std::endl; //string
    //-------------------------------------------------------------

    std::cout << "\nil Minimo :" << std::endl;
    std::cout << min(5, 10)<< std::endl; //int
    std::cout << min(2.5, 2.7)<< std::endl; //float
    std::cout << min("ahmed" , "Mera")<< std::endl; //string
    //------------------------------------------------------------------
    int arr1 [5] = {4,10 , 3, 5, 11};
    float arr2 [5] = {5.4 ,2.5 , 3.8, 4.1, 5.2};
    char arr3 [10] = {"mera"};
    std::string arr4 [3] = {"mera", "gabri", "shehan"};



    std::cout << "\nsort :" << std::endl;
    sort(arr1, 5);//int
    sort(arr2, 5); //float
    sort(arr3 , strlen(arr3)); //string
    sort(arr4 , 3); //string

    //------------------------------------------------------------------

    return 0;
}

template <class t> t sort(t array[] , int dim ){
    int i , j ;
    t app;
    //std::cout << typeid(array).name() << std::endl;
        for (i = 0; i < dim - 1; i++){
            for(j = i; j < dim  ; j++) {
                if(array[i] > array[j]){
                    app = array[i];
                    array[i] = array[j];
                    array[j] = app;
                }
            }
        }



    for(i = 0; i < dim; i++){
        std::cout << array[i] << "\t" ;
    }
    std::cout << "\n";
}