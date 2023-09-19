#ifndef INDEX_H
#define INDEX_H
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cctype>
using namespace std;
struct Student
{
    int id;
    string lastName;
    string firstName;
    string ssn;
    float test[4];
    float final;
    string letterGrade;
};
void readFileIntoVector(vector <Student> &v, ifstream & file);
void setPointersToVector(vector <Student *> &p, vector <Student> &v);
void sortPointers(vector <Student *> & pointers, int input);
void printPointers(vector <Student *> & pointers,int input);
void printMenu();
void collectValidInput(int &input);
void searchFor(vector <Student *> & pointers, string s, int input);
string compareValue(Student * s, int input);


#endif