#include "header.h"


int main() {
    vector<NODE *> structNodes;
    vector<ROUTE *> result;
     NODE * HEAD = nullptr;

    srand(time(nullptr));
    fullStructNodes(&structNodes);
    linking(structNodes, HEAD);
    print(HEAD);
    CALC(structNodes, result);
    cout << "\n \n" << endl;
    print(result);


    return 0;
}
