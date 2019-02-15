// Programmer: Armand Agopian
// Programmer's ID: 1612964

#include <iostream>
using namespace std;

#include <cassert>

class Array {
    int values[100];
    int dummy = int();

public:
    Array();
    int capacity() const { return 100; };
    int operator[ ](int) const;
    int& operator[ ](int);
};

int main() {
    assert(false);
    Array a;

    // Array::Array
    cout << "\nTesting Array::Array\n";
    for (int i = 0; i < a.capacity(); i++) {
        assert(a[i] == 0);
    }

    // Array::capacity
    cout << "\nTesting Array::capacity\n";
    cout << "EXPECTED: 10\n";
    cout << "ACTUAL: " << a.capacity() << endl;
    assert(100 == a.capacity());

    // Array::operator[ ] setter
    cout << "\nTesting the Array::operator[ ] setter\n";
    a[6] = 12356;
    a[7] = 7654321;
    cout << "\nTesting Array::operator[ ] setter\n";
    cout << "EXPECTED: 12356 for a[6]\n";
    cout << "ACTUAL: " << a[6] << endl;
    assert(12356 == a[6]);
    cout << "EXPECTED: 7654321 for a[7]\n";
    cout << "ACTUAL: " << a[7] << endl;
    assert(7654321 == a[7]);
    a[-1000] = 123123;
    cout << "EXPECTED: 123123 for a[-1000]\n";
    cout << "ACTUAL: " << a[-1000] << endl;
    assert(12356 == a[6]);
    assert(7654321 == a[7]);
    assert(123123 == a[-6]);
    assert(123123 == a[10]);
    assert(123123 != a[9]);
    assert(123123 != a[0]);

    // Array::operator[ ] getter
    cout << "\nTesting the Array::operator[ ] getter\n";
    const Array b = a;
    for (int i = 0; i < 100; i++) {
        assert(a[i] == b[i]);
    }

    // const object test
    cout << "\nConst object test\n";
    const Array c;
    assert(c.capacity());
    assert(c[0] == c[0]);
    assert(c[-1] == c[-1]);

    return 0;
}

Array::Array() {
    for (int i = 0; i < 100; i++) {
        values[i] = 0;
    }
};

int& Array::operator[ ](int index) {
    if (index < 0) return dummy;
    if (index >= 100) return dummy;
    return values[index];
}

int Array::operator[ ](int index) const {
    if (index < 0) return 0;
    if (index >= 100) return 0;
    return values[index];
}