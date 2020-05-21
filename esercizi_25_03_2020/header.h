//
// Created by Ahmed on 27/03/2020.
//

#ifndef ESERCIZI_25_03_2020_HEADER_H
#define ESERCIZI_25_03_2020_HEADER_H

#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;
static char NAME_FILE [20] = "passaggi.txt";
static fstream file;

struct EMPLOYEE {
    string ID;
    int DAY, MONTH, YEAR, HOUR, MINUTES, TOTAL_MINUTES;
};

struct EMPLOYEES {
    struct EMPLOYEE * employee;
    int COUNT;
};

void readFromFile(char * nameFile, struct EMPLOYEES *data);
void writeOnFile(char * nameFile, struct EMPLOYEES data);
void pass(string id);
int search(string id);
int totalEmployees( struct EMPLOYEES data);
void showEmployees( struct EMPLOYEES data);
int totalHours(string id,struct EMPLOYEES data);


#endif //ESERCIZI_25_03_2020_HEADER_H
