// Programmer: Armand Agopian
// Programmer's ID: 1612964

#include <iostream>
#include <sstream>

using namespace std;

#include "StaticArray.h"

int main() {
    StaticArray<double, 100> a;
    StaticArray<bool, 100> flag;
    string input;
    int index, count = 0;
    double value;

    for(int i = 0; i < flag.capacity(); i++) {
        flag[i] = false; //Since dummy for bool in cpp is true
    }

    do {
        cout << "Input an index and a value [Q to quit]: ";
        getline(cin, input);
        if (tolower(input.at(0)) != 'q') {
            stringstream(input) >> index >> value;
            a[index] = value;
            flag[index] = true;
        }
    } while (tolower(input.at(0)) != 'q');

    for (int i = 0; i < a.capacity(); i++) {
        if (flag[i]) {
            count++;
        }
    }
    cout << endl;
    cout << "You stored this many values: " << count << endl;
    cout << "The index-value pairs are: " << endl;
    for (int i = 0; i < a.capacity(); i++) {
        if (flag[i]) {
            cout << i << " -> " << a[i] << endl;
        }
    }

    cout << endl;
    do {
        cout << "Input an index for me to look up [Q to quit]: ";
        getline(cin, input);
        if (tolower(input.at(0)) != 'q') {
            stringstream(input) >> index;
            if (flag[index]) {
                cout << "Found it -- the value stored at " << index << " is " << a[index] << endl;
            } else {
                cout << "I didn't find it" << endl;
            }
        }
    } while (tolower(input.at(0)) != 'q');

    return 0;
}