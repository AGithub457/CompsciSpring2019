// Programmer: Armand Agopian
// Programmer's ID: 1612964

#include <iostream>

using namespace std;

#include <cassert>

#include "StaticArray.h"
#include "StaticArray.h" // ifndef test

int main() {
    StaticArray<int, 100> a;

    // StaticArray::StaticArray
    cout << "\nTesting StaticArray::StaticArray\n";
    for (int i = 0; i < a.capacity(); i++) {
        assert(a[i] == 0);
    }

    // StaticArray::capacity
    cout << "\nTesting StaticArray::capacity\n";
    cout << "EXPECTED: 100\n";
    cout << "ACTUAL: " << a.capacity() << endl;
    assert(100 == a.capacity());

    // StaticArray::operator[ ] setter
    cout << "\nTesting the StaticArray::operator[ ] setter\n";
    a[6] = 12356;
    a[7] = 7654321;
    cout << "\nTesting StaticArray::operator[ ] setter\n";
    cout << "EXPECTED: 12356 for a[6]\n";
    cout << "ACTUAL: " << a[6] << endl;
    assert(12356 == a[6]);
    cout << "EXPECTED: 7654321 for a[7]\n";
    cout << "ACTUAL: " << a[7] << endl;
    assert(7654321 == a[7]);
    a[-1000] = 123123;
    cout << "EXPECTED: 123123 for a[-1000]\n";
    cout << "ACTUAL: " << a[-1000] << endl;
    assert(123123 == a[-1000]);

    // StaticArray::operator[ ] getter
    cout << "\nTesting the StaticArray::operator[ ] getter\n";
    const StaticArray<int, 100> b = a;
    for (int i = 0; i < b.capacity(); i++) {
        assert(a[i] == b[i]);
    }

    // const object test
    cout << "\nConst object test\n";
    const StaticArray<int, 100> c;
    assert(c.capacity());
    assert(c[0] == c[0]);
    assert(c[-1] == c[-1]);

    cout << "String test!!!!!!!!!!!!!!!!!" << endl;

    StaticArray<string, 100> f;

    // StaticArray::StaticArray
    cout << "\nTesting StaticArray::StaticArray\n";
    for (int i = 0; i < f.capacity(); i++) {
        assert(f[i] == "0");
    }

    // StaticArray::capacity
    cout << "\nTesting StaticArray::capacity\n";
    cout << "EXPECTED: 100\n";
    cout << "ACTUAL: " << f.capacity() << endl;
    assert(100 == f.capacity());

    // StaticArray::operator[ ] setter
    cout << "\nTesting the StaticArray::operator[ ] setter\n";
    f[6] = "six";
    f[7] = "seven";
    f[-1000] = "back";
    cout << "\nTesting StaticArray::operator[ ] setter\n";
    cout << "EXPECTED: six for a[6]\n";
    cout << "ACTUAL: " << f[6] << endl;
    assert("six" == f[6]);
    cout << "EXPECTED: seven for a[7]\n";
    cout << "ACTUAL: " << f[7] << endl;
    assert("seven" == f[7]);
    cout << "EXPECTED: back for a[-1000]\n";
    cout << "ACTUAL: " << f[-1000] << endl;
    assert("back" == f[-1000]);

    // StaticArray::operator[ ] getter
    cout << "\nTesting the StaticArray::operator[ ] getter\n";
    const StaticArray<string, 100> g = f;
    for (int i = 0; i < g.capacity(); i++) {
        assert(f[i] == g[i]);
    }

    // const object test
    cout << "\nConst object test\n";
    const StaticArray<string, 100> h;
    assert(h.capacity());
    assert(h[0] == h[0]);
    assert(h[-1] == h[-1]);

    return 0;
}