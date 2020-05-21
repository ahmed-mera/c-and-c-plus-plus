//
// Created by Ahmed on 27/03/2020.
//

#include "header.h"

void readFromFile(char * nameFile, struct EMPLOYEES  * data){
    string line;
    int index = 0;
    file.open(nameFile, ios::in); // try opn file
    if (! file.is_open() ) file.open(nameFile); // check file
    data->COUNT = 0;
    while (getline(file , line )) data->COUNT++;

    file.close();
    file.open(nameFile);
    data->employee = new struct EMPLOYEE [data->COUNT]; //allocate space
    while (! file.eof()){
        file >> data->employee[index].ID
             >> data->employee[index].HOUR
             >> data->employee[index].MINUTES
             >> data->employee[index].DAY
             >> data->employee[index].MONTH
             >> data->employee[index].YEAR;
        index++;
    }
    file.close();
}
void writeOnFile(char * nameFile, struct EMPLOYEES data){
    file.open(nameFile, ios::app);
    for (int i = 0; i < data.COUNT; ++i) {
        file << data.employee[i].ID << "\t"
             << data.employee[i].HOUR << "\t"
             << data.employee[i].MINUTES << "\t"
             << data.employee[i].DAY << "\t"
             << data.employee[i].MONTH << "\t"
             << data.employee[i].YEAR <<endl;
    }
}

void pass(string id) {
    time_t timeNow = time(nullptr); /// get time now
    tm * TIME = localtime(&timeNow); /// create object time to mange date and time
    struct EMPLOYEES data{};
    data.COUNT = 1;
    data.employee = new struct EMPLOYEE; //allocate space
    data.employee->ID = id;
    data.employee->HOUR = TIME->tm_hour;
    data.employee->MINUTES = TIME->tm_min + 1;
    data.employee->DAY =TIME->tm_mday;
    data.employee->MONTH =TIME->tm_mon + 1;
    data.employee->YEAR =TIME->tm_year + 1900;
    writeOnFile(NAME_FILE, data);
}
int search(string id) {
    int count = 0;
    string ID;
    file.open(NAME_FILE, ios::in); // try opn file
    while(! file.eof()){
        file >> ID;
        if (ID == id) count++;
        getline(file , ID);
    }
    return count;
}

int totalEmployees( struct EMPLOYEES data) {
    int total = 0;
    for (int i = 0; i < data.COUNT ; ++i)
        total = data.COUNT - search(data.employee[i].ID);

    return total;
}

void showEmployees( struct EMPLOYEES data) {
    string line;
    int i = 1;
    file.open(NAME_FILE, ios::in); // try opn file
    while (getline(file , line ))
        cout << i++ << ") " << line << endl;
}


int totalHours(string id, struct EMPLOYEES data){
    int  hoursFirst = 0, hoursLast = 0, minutesFirst = 0 , minutesLast = 0 , tmp;
    string ID;
    file.open(NAME_FILE, ios::in); // try opn file
    while(! file.eof()){
        file >> ID;
        if (ID == id){
            file >> tmp;
            if(!hoursFirst) {
                hoursFirst = tmp;
                file >> tmp;
                minutesFirst = tmp;
            } else{
                hoursLast = tmp;
                file >> tmp;
                minutesLast = tmp;
            }
        }
        getline(file , ID);
    }
    return (hoursLast - hoursFirst) * 60 + (minutesLast - minutesFirst);
}