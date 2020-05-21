#include "header.h"
int main() {
    int dim , i ;
    std :: cout << "quanti oggetti voui :_" ;
    std::cin >> dim;
    for (int j = 0; j < dim ; ++j) {
        createObject object;
        createNodo(object);
    }

   show();
    return 0;
}