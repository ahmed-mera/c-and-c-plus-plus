//
// Created by Ahmed on 10/12/2019.
//

#include "header.h"

//! C-R-U-D
// create the vector and upload it with random
std::vector <int> CreateAndUpload () {
    int dim;
    std::vector <int> myVector;
    std::cout << "Enter The dim of Vector :_ " ;
    std::cin >> dim;
    if(!dim){
        std::cout << "You Can not enter 0 for size of vector :( so i put his of 1 element :) " << std::endl;
        dim = 1;
    }
    for (int i = 0; i < dim ; ++i) {
        myVector.push_back(rand() % 100 + 1);
    }
    return myVector;
}

// show the elements in the vector
void Show (std::vector <int> myVector) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout << std::endl << "Size of Vector =  " ;
    SetConsoleTextAttribute(hConsole, 3);
    std::cout << myVector.size() ;
    SetConsoleTextAttribute(hConsole, 0);
    std::cout << " elements " << std::endl;
    if(! myVector.empty()) {
        std::cout << "Index ===> value" << std::endl;
    }else{
        std::cout << "\n" <<std::endl;
    }
    for (int i = 0; i < myVector.size() ; ++i) {
        SetConsoleTextAttribute(hConsole, 01);
        std::cout << i << " ) ";
        SetConsoleTextAttribute(hConsole, 0);
        std::cout << " ===> ";
        SetConsoleTextAttribute(hConsole, 9);
        std::cout << "[ " <<  myVector[i] << " ]\n";
    }
    SetConsoleTextAttribute(hConsole, 0);
}

// update the vector
bool Update (std::vector <int>& myVector) {
    int choose , pos , newValue;
    system("cls");
    std::cout << std::endl << "1) Delete Element \n2) Change Element \n3) Add Element \nChoose:_";
    std::cin  >> choose;
    std::cin.ignore();
    switch (choose){
        case 1:
            system("cls");
            std::cout << "Enter The Index :_";
            std::cin >> pos;
            std::cin.ignore();
            if( pos < 0 ||  pos >= myVector.size()) {
                std::cout << "Position does not exist :( " << std::endl;
                return false;
            }
            myVector.erase(myVector.begin() + pos);
            std::cout << "Element is deleted successfully " << std::endl;
            //Show(myVector);
            return true;
        case 2:
            system("cls");
            std::cout << "Enter The Index :_";
            std::cin >> pos;
            std::cin.ignore();
            std::cout << "Enter The new value :_";
            std::cin >> newValue;
            std::cin.ignore();
            if( pos < 0 || pos >= myVector.size()) {
                std::cout << "Position does not exist :( " << std::endl;
                return false;
            }
            myVector.at(pos) = newValue;
            std::cout << "Element is updated successfully " << std::endl;
            //Show(myVector);
            return true;
        case 3:
            system("cls");
            std::cout << "Enter The new value :_";
            std::cin >> newValue;
            std::cin.ignore();
            system("cls");
            std::cout << "1) Front \n2) Tail \n3) Enter position \nChoose :_ ";
            std::cin >> choose;
            std::cin.ignore();
            switch (choose){
                case 3:
                    std::cout << "Enter The Index :_";
                    std::cin >> pos;
                    std::cin.ignore();
                    if( pos < 0 || ( pos >= myVector.size() && pos != 0 )) {
                        std::cout << "Position does not exist :( " << std::endl;
                        return false;
                    }
                    myVector.insert(myVector.begin() + pos, newValue);
                    break;
                case 2:
                    myVector.push_back(newValue);
                    break;
                case 1:
                    myVector.insert(myVector.begin(), newValue);
                    break;
                default:
                    std::cout << "Position does not exist :(" << std::endl;
                    return false;
            }
            std::cout << "Element is added successfully :)  " << std::endl;
            return true;
        default :
            std::cout << "Your choose is not exist :( you can try again :) " << std::endl;
            return false;
    }
}

// delete element of the vector
void Delete (std::vector <int>& myVector) {
    int confirm;
    system("cls");
    std::cout << "You are sure to clear this vector ? \n For No  Enter ( 0 ) , For Yes Enter ( 1 ) :_";
    std::cin >> confirm ;
    std::cin.ignore();
    if(confirm) {
        myVector.clear();
        std::cout << "This vector is cleared successfully :) " << std::endl;
    }
}

// search
bool Search (std::vector <int> myVector) {
    int ele;
    std::cout << "Enter The value of element :_";
    std::cin >> ele;
    std::cin.ignore();
    for (int i = 0; i < myVector.size(); ++i){
        if(myVector[i] == ele ){
            std::cout << "The element you search in position ==>" << i + 1 << std::endl;
            return true;
        }
    }
    return false;
}