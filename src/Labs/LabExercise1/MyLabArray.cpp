// Programmer: Armand Agopian
// Programmer's ID: 1612964
#include <iostream>
#include <sstream>

using namespace std;

class Array {
    int values[10];

public:
    void setAtIndex(int, int);
    const int getAtIndex(int);
    const int capacity() { return 10; }
};

int main() {
    cout << "Programmer: Armand Agopian" << endl;
    cout << "Programmer's ID: 1612964" << endl;
    cout << "File: " << __FILE__ << endl;

    char ch;
    string input;
    int index, value;
    Array a;

    do {
        cout << "Input an index and a value [q to quit]: ";
        getline(cin, input);
        stringstream(input) >> index >> ch >> value;
        cout << endl;
    } while (tolower(input.at(0)) != 'q');
}

void Array::setAtIndex(int index, int value) {
    if (index >= 0 && index < 10)
        values[index] = value;
}

const int Array::getAtIndex(int index) {
    if (index < 0 || index >= 10)
        return 0;

    return values[index]; // no "else" needed
}