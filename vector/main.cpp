#include "header.h"

int main() {
    srand(time(NULL)); // call function srand for generate a casual number
    std::vector <int> myVector;
    int choose ;
    while(true){
        std::cout << "1) Create The Vector \n2) Show the vector \n3) Update the vector \n4) Delete Vector \n5) Search \n0) Exit \nChoose :_";
        std::cin >> choose;
        std::cin.ignore();
        switch (choose){
            case 0:
                system("cls");
                std::cout << "Good Bye , See you later :) " << std::endl;
                exit(0);
                break;
            case 1:
                system("cls");
                myVector = CreateAndUpload(); // call function CreateAndUpload for creating and fill the vector
                std::cout << "The Vector is created successfully " << std::endl;
                break;
            case 2:
                system("cls");
                std::cout << "---------------------------------------------------------------------" << std::endl;
                Show(myVector); // call function show for showing the elements of the vector
                std::cout << "---------------------------------------------------------------------" << std::endl;
                break;
            case 3:
                system("cls");
                Update(myVector);
                break;
            case 4:
                system("cls");
                Delete(myVector);
                break;
            case 5:
                system("cls");
                 if(!Search(myVector)){
                     std::cout << "The element does not exist in in Vector " << std::endl;
                 }
                break;
            default:
                std::cout << "You must choose one of this choises, try again :) " << std::endl;
                break;
        }
    }
    return 0;
}
