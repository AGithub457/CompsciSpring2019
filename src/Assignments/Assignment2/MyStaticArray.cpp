// Programmer: Armand Agopian
// Programmer's ID: 1612964

#include <iostream>
#include <sstream>

using namespace std;

#include "StaticArray.h"

int main() {
    Array<double, 100> a;
    Array<bool, 100> flag;
    string input;
    int index, count = 0;
    double value;
    do {
        cout << "Input an index and a value [Q to quit]: ";
        getline(cin, input);
        if (tolower(input.at(0)) != 'q') {
            stringstream(input) >> index >> value;
            a[index] = value;
            flag[index] = true;
        }
    } while (input != "q");

    for(int i = 0; i < 100; i++) {
        if(flag[i]) {
            count++;
        }
    }
    cout << endl;
    cout << "You stored this many values: " << count << endl;
    cout << "The index-value pairs are: " << endl;
    for (int i = 0; i < 100; i++) {
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
    } while (input != "q");

    return 0;
}