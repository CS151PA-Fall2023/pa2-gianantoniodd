#include "index.h"

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
void setPointersToVector(vector <Student *> &p, vector <Student> &v)
{
    for (long unsigned int i = 0; i < v.size(); i++)
    {
        Student * tmpptr;
        tmpptr = & v[i];
        p.push_back(tmpptr);
    }
}
void sortPointers(vector <Student *> & pointers, int input)
{
    bool sorted;
    do
    {
        sorted = true;
        
        for (long unsigned int i = 0; i < pointers.size()-1; i++)
        {
            cout << "hello"<<endl;
            Student * tmpptr;
            if (!(input%2))// if even sort by last name
            {
                if ((*pointers[i]).lastName > (*pointers[i+1]).lastName)
                {
                    sorted = false;
                    tmpptr = pointers[i];
                    pointers[i] = pointers[i+1];
                    pointers[i+1] = tmpptr;
                }
            }
            if (input%2)// if odd sort by ssn
            {
                if (pointers[i]->ssn > pointers[i+1]->ssn)
                {
                    sorted = false;
                    tmpptr = pointers[i];
                    pointers[i] = pointers[i+1];
                    pointers[i+1] = tmpptr;
                }
            }
        }
    }while (!sorted);
}
/**
 * @brief 
 * 
 * @param pointers 
 * @param input 
 */
void printPointers(vector <Student *> & pointers,int input)
{
    string sortBy[] = {"Last name","SSN"};

    cout << left << setw(40)<< "students by " << sortBy[input] << endl;
    cout << "ID Last Name   First Name  SSN         Grade" << endl;
    for (long unsigned int i = 0; i < pointers.size(); i++) 
    {
        cout << right << setw(2)<< (*pointers[i]).id <<" "<< left << setw(12)
         <<(*pointers[i]).lastName << left << setw(12)<<(*pointers[i]).firstName
         <<setw(12) <<(*pointers[i]).ssn<< (*pointers[i]).letterGrade << endl;
    }


}
void printMenu()
{
cout << "1. Print data in ascending order by last name\n";
cout << "2. Print data in ascending order by SSN\n";
cout << "3. Search by last name\n";
cout << "4. Search by SSN\n";
cout << "5. Exit\n";
cout << "\n";
cout << "Select a Menu: _";
}
void collectValidInput(int &input)
{
    cin >> input;
    while ((input > 5) || (input < 1))
    {
        cin.get();
        cout << "invalid value"<< endl;
        cout << "Please enter a value between 1 and 5" << endl;
        cin >> input;
    }

}
void searchFor(vector <Student *> & pointers, string s, int input)
{

}