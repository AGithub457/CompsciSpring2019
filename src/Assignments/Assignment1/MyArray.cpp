// Programmer: Armand Agopian
// Programmer's ID: 1612964

#include <iostream>
#include <sstream>

using namespace std;

class Array {
    int values[100];
    int dummy = int();

public:
    Array();

    int capacity() const { return 100; };
    int operator[](int) const;
    int &operator[](int);
};

int main() {
    Array a;
    string input;
    int index, value, count = 0;
    do {
        cout << "Input an index and a value [Q to quit]: ";
        getline(cin, input);
        if (tolower(input.at(0)) != 'q') {
            stringstream(input) >> index >> value;
            if ((index >= 0) && (index <= 99)) {
                a[index] = value;
                count++;
            }
        }
    } while (input != "q");

    cout << endl;
    cout << "You stored this many values: " << count << endl;
    cout << "The index-value pairs are: " << endl;
    for (int i = 0; i < 100; i++) {
        if (a[i] != 0) {
            cout << i << " -> " << a[i] << endl;
        }
    }

    cout << endl;
    do {
        cout << "Input an index for me to look up [Q to quit]: ";
        getline(cin, input);
        if (tolower(input.at(0)) != 'q') {
            stringstream(input) >> index;
            if (a[index] != 0) {
                cout << "Found it -- the value stored at " << index << " is " << a[index] << endl;
            } else {
                cout << "I didn't find it" << endl;
            }
        }
    } while (input != "q");

    return 0;
}

Array::Array() {
    for (int i = 0; i < 100; i++) {
        values[i] = 0;
    }
};

int &Array::operator[](int index) {
    if (index < 0) return dummy;
    if (index >= 100) return dummy;
    return values[index];
}

int Array::operator[](int index) const {
    if (index < 0) return 0;
    if (index >= 100) return 0;
    return values[index];
}