// Programmer: Armand Agopian
// Programmer's ID: 1612964


#include <iostream>

using namespace std;

int main() {
    string input;

    cout << "1 + 1 = ";
    getline(cin, input);

    if (input == "2") {
        cout << "Correct!";
    } else {
        cout << "Incorrect :(";
    }

    return 0;
}