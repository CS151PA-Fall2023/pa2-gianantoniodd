/**
 * @file main.cpp
 * @author David Durrant
 * @brief allows user to look thru search and sort data related to students
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
    vector <Student *> lastNamePointers;                //create pointers
    vector <Student *> firstNamePointers;
    vector <Student *> ssnPointers;
    setPointersToVector(firstNamePointers, students);   //initialize pointers
    setPointersToVector(lastNamePointers, students);
    setPointersToVector(ssnPointers, students);
    sortPointers(firstNamePointers, 1);                 //sorts pointers
    sortPointers(lastNamePointers, 2);
    sortPointers(ssnPointers, 3);//int parameter tells function what value to sort by


    int input = -1;
    while (true)
    {
        printMenu();//print menu, collect valid input, display. while not 7, keeps looping
        collectValidInput(input);
        if (input ==1)
        {
            printPointers(firstNamePointers,input);
            cout <<endl;
        }
        if (input ==2)
        {
            printPointers(lastNamePointers,input);
            cout <<endl;
        }
        if (input == 3)
        {
            printPointers(ssnPointers,input);
            cout <<endl;
        }
        if (input == 4)
        {
            cout <<"search first name of student";
            string search;
            cin >> search;
            searchFor(firstNamePointers, search, 1);
        }
        if (input == 5)
        {
            cout <<"search last name of student";
            string search;
            cin >> search;
            searchFor(lastNamePointers, search, 2);
        }
        if (input == 6)
        {
            cout <<"search by ssn of student";
            string search;
            cin >> search;
            searchFor(ssnPointers, search, 3);
        }
        if (input ==7) break;
        cin.ignore();//waits for user to press enter to go to next screen.
        cin.get();



    
    }


    return 0;
}