// Programmer: Sibbons Shrestha
// Programmer's ID: 1595562
// Programmer: Armand Agopian
// Programmer's ID: 1612964

#ifndef COMPSCISPRING2019_LABEXERCISE0_H
#define COMPSCISPRING2019_LABEXERCISE0_H

#include<string>
#include<iostream>

using namespace std;

void welcome() {
    string firstName;
    string lastName;

    cout << "Please enter your first name:" << endl;
    getline(cin, firstName);
    cout << "Please enter your last name:" << endl;
    getline(cin, lastName);

    cout << endl << "COMSC 210 : Lab Excercise Zero" << endl;
    cout << "=====================================" << endl;
    cout << firstName << " " << lastName << " , Welcome to COMSC210-2704" << endl;
    cout << firstName << endl;
    cout << lastName << endl;
    cout << "Enjot the hybrid format class!!" << endl;
    cout << lastName << " " << firstName << endl;
    cout << "This class will meet once a week at 11:10 in L-149 on Thursday" << endl;
    cout << "Program ended with exit code : 0" << endl;
}

#endif