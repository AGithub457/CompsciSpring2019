// Programmer: Armand Agopian
// Programmer's ID: 1612964

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "Stack.h"

int main() {
    cout << "Programmer: Armand Agopian" << endl;
    cout << "Programmer's ID: 1612964" << endl;
    cout << "File: " << __FILE__ << endl << endl;

    string input;
    bool isQ = false;
    Stack<string> stack;

    while(!isQ) {
        cout << "Enter: " << endl;
        getline(cin, input);

        if(tolower(input.at(0)) == 'q') {
            isQ = true;
        } else {
            switch(input.at(0)) {
                case '+':
            }
            stack.push(input);
        }
    }

    return 0;
}