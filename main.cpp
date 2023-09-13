/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "index.h"
#include <iomanip>
#include <iostream>
#include <string>
int main()
{
    vector <Student> students;
    ifstream file;
    file.open("grades.csv");
    readFileIntoVector(students, file);
    file.close();
    vector <Student *> lastNamePointers;
    vector <Student *> ssnPointers;
    setPointersToVector(lastNamePointers, students);
    setPointersToVector(ssnPointers, students);
    sortPointers(lastNamePointers, 0);
    sortPointers(ssnPointers, 1);

    int input = -1;
    while (true)
    {
        printMenu();
        collectValidInput(input);
        
        if (input ==1)
        {
            printPointers(lastNamePointers,0);
            cout <<endl;
        }
        if (input == 2)
        {
            printPointers(ssnPointers,1);
            cout <<endl;
        }
        if (input == 3)
        {
            cout <<"search last name of student";
            string search;
            cin >> search;
            searchFor(lastNamePointers, search, 0);
        }
        if (input == 4)
        {
            cout <<"search by ssn of student";
            string search;
            cin >> search;
            searchFor(ssnPointers, search, 0);
        }
        if (input ==5) break;
        cin.ignore();
        cin.get();



    
    }


    return 0;
}