#include "header.h"


int main(int argc, char ** argv) {
    struct EMPLOYEES data{};

    readFromFile(NAME_FILE, &data);

    cout << argc <<endl;

    if(argc == 2){
        cout << "ci sono " << totalEmployees(data) << "dipendenti diversi." <<endl;
        exit(0);
    }


    if(argc == 3){
        cout << "ci sono " << totalHours(argv[2], data) << "dipendenti diversi." <<endl;
        exit(0);
    }

    //menu

    return 0;
}


