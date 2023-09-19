/**
 * @file index.cpp
 * @author David Durrant
 * @brief defines functions for index project
 * @version 0.1
 * @date 2023-09-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "index.h"
/**
 * @brief reads thru file and coppys information into student object vector
 * 
 * @param v vector of student objects to populate
 * @param file ifstream file object to read
 */
void readFileIntoVector(vector <Student> &v, ifstream & file)
{
    string temp;
    getline(file, temp);
    while (true)
    {
        Student j;
        char delim;
        file >> j.id>>delim;
        
        getline(file, j.lastName ,',');
        getline(file, j.firstName ,',');
        getline(file, j.ssn ,',');
        
        file >> j.test[0]>>delim;
        file >> j.test[1]>>delim;
        file >> j.test[2]>>delim;
        file >> j.test[3]>>delim;
        file >> j.final>>delim;
        file >> j.letterGrade;

        file.get();
        v.push_back(j);
        if (file.peek() == EOF) break;
    }
}
/**
 * @brief Set the Pointers To Vector object
 * 
 * @param p vectors of pointers to set
 * @param v vector of student
 */
void setPointersToVector(vector <Student *> &p, vector <Student> &v)
{
    for (long unsigned int i = 0; i < v.size(); i++)
    {
        Student * tmpptr;
        tmpptr = & v[i];
        p.push_back(tmpptr);
    }
}
/**
 * @brief sorts vect of pointers
 * 
 * @param pointers vector of pointers to be sorted
 * @param input determines what mmember variable to sort by
 */
void sortPointers(vector <Student *> & pointers, int input)
{
    bool sorted;
    do
    {
        sorted = true;
        
        for (long unsigned int i = 0; i < pointers.size()-1; i++)
        {
            Student * tmpptr;

            if (compareValue(pointers[i], input) > compareValue(pointers[i+1], input))//bubble sort
            {
                sorted = false;
                tmpptr = pointers[i];
                pointers[i] = pointers[i+1];
                pointers[i+1] = tmpptr;
            }
        }
    }while (!sorted);
}
/**
 * @brief takes array of pointers and displays them with proper headers of what was
 * searched / sorted by
 * 
 * @param pointers vector of pointers to be printed
 * @param input determines what to tell user data was sorted by
 */
void printPointers(vector <Student *> & pointers,int input)
{
    string sortBy[] = {"First name","Last name","SSN"};//list of possible headers for printed menu

    cout << left << setw(40)<< "students by " << sortBy[input-1] << endl;//header determined by input
    cout << "ID Last Name   First Name  SSN         Grade" << endl;
    for (long unsigned int i = 0; i < pointers.size(); i++) 
    {
        cout << right << setw(2)<< (*pointers[i]).id <<" "<< left << setw(12)
         <<(*pointers[i]).lastName << left << setw(12)<<(*pointers[i]).firstName
         <<setw(12) <<(*pointers[i]).ssn<< (*pointers[i]).letterGrade << endl;
    }


}
/**
 * @brief prints out menu
 * 
 */
void printMenu()
{
cout << "1. Print data in ascending order by first name\n";
cout << "2. Print data in ascending order by last name\n";
cout << "3. Print data in ascending order by SSN\n";
cout << "4. Search by first name\n";
cout << "5. Search by last name\n";
cout << "6. Search by SSN\n";
cout << "7. Exit\n";
cout << "\n";
cout << "Select a Menu: _";
}
/**
 * @brief collects input and validates it from user
 * 
 * @param input 
 */
void collectValidInput(int &input)
{
    cin >> input;
    while ((input > 7) || (input < 1))
    {
        cin.get();
        cout << "invalid value"<< endl;
        cout << "Please enter a value between 1 and 5" << endl;
        cin >> input;
    }

}
/**
 * @brief bianary search. searches for all elements if array that match the search
 * calls print function and displays to user
 * 
 * @param pointers sorted pointers to student objects
 * @param s value to search
 * @param input determines what member variable to compare
 */
void searchFor(vector <Student *> & pointers, string s, int input)
{
    int low = 0;
    int high = pointers.size()-1;
    int mid = (high + low)/2;
    vector <Student *> hitList;
    while (low +1 != high)//searches thru starting at mid
    {
        if (s == compareValue(pointers[mid], input))
        {
            hitList.push_back(pointers[mid]);//if hit, add to a vector
            break;
        }
        if (s > compareValue(pointers[mid], input))
        {
            low = mid;
            mid = (high + low)/2;//if value is less, bounds move up
        }
        if (s < compareValue(pointers[mid], input))
        {
            high = mid;
            mid = (high + low)/2;//if value is greater, bounds move down
        }
    }
    int i = 1;
    // checks the elements above and below the hit, if they also match the search adds to array
    while (s == compareValue(pointers[mid+i], input))
    {
        hitList.push_back(pointers[mid-1]);
        i++;
    }
    i = 1;
    while (s == compareValue(pointers[mid-i], input))
    {
        hitList.push_back(pointers[mid-1]);
        i++;
    }
    if (hitList.size() == 0) cout << "There were zero matches...\n";
    else printPointers(hitList, input);//prints list of all students that match search
    
}
/**
 * @brief determines wich member variable to use to compare for search and sorts
 * based on user inputs
 * 
 * @param s vector of students by reference
 * @param input user selected, decides what data to sort or search by
 * @return string to be compared
 */
string compareValue(Student * s, int input)
{
    if (input == 1) return s->firstName;
    if (input == 2) return s->lastName;
    if (input == 3) return s->ssn;
    return "";
}