//
// Created by Ahmed on 10/12/2019.
//

#ifndef VECTOR_HEADER_H
#define VECTOR_HEADER_H

#endif //VECTOR_HEADER_H

#include <iostream>
#include <vector>
#include <ctime>
#include <windows.h>
//! C-R-U-D
//! sort and search
std::vector <int> CreateAndUpload (); // create the vector
void Show (std::vector <int> myVector); // show the elements in the vector
bool Update (std::vector <int>& myVector); // update the vector
void Delete (std::vector <int>& myVector); // delete element of the vector
bool Search (std::vector <int> myVector); // search an element of the vector