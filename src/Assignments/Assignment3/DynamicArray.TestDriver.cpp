// Programmer: Armand Agopian
// Programmer's ID: 1612964

#include <iostream>

using namespace std;

#include <cassert>

#include "DynamicArray.h"
#include "DynamicArray.h" // ifndef test

int main() {
    DynamicArray<int> a(100);

    // DynamicArray::DynamicArray
    cout << "\nTesting DynamicArray::DynamicArray\n";
    for (int i = 0; i < a.capacity(); i++) {
        assert(a[i] == 0);
    }

    // DynamicArray::capacity
    cout << "\nTesting DynamicArray::capacity\n";
    cout << "EXPECTED: 100\n";
    cout << "ACTUAL: " << a.capacity() << endl;
    assert(100 == a.capacity());

    // DynamicArray::operator[ ] setter
    cout << "\nTesting the DynamicArray::operator[ ] setter\n";
    a[6] = 12356;
    a[7] = 7654321;
    cout << "\nTesting DynamicArray::operator[ ] setter\n";
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

    // DynamicArray::operator[ ] getter
    cout << "\nTesting the DynamicArray::operator[ ] getter\n";
    const DynamicArray<int> b = a;
    for (int i = 0; i < b.capacity(); i++) {
        assert(a[i] == b[i]);
    }

    // const object test
    cout << "\nConst object test\n";
    const DynamicArray<int> c(100);
    assert(c.capacity());
    assert(c[0] == c[0]);
    assert(c[-1] == c[-1]);

    // object copy test
    cout << "\nObject copy test\n";
    DynamicArray<int> d = a;
    assert(a.capacity() == d.capacity());
    for (int i = 0; i < a.capacity(); i++) {
        assert(a[i] == d[i]);
    }

    // object assignment test
    cout << "\nObject assignment test\n";
    DynamicArray<int> e; e = a;
    assert(a.capacity() == e.capacity());
    for (int i = 0; i < a.capacity(); i++) {
        assert(a[i] == e[i]);
    }

    cout << "String test!!!!!!!!!!!!!!!!!" << endl;

    DynamicArray<string> f(100);

    // DynamicArray::DynamicArray
    cout << "\nTesting DynamicArray::DynamicArray\n";
    for (int i = 0; i < f.capacity(); i++) {
        assert(f[i] == "0");
    }

    // DynamicArray::capacity
    cout << "\nTesting DynamicArray::capacity\n";
    cout << "EXPECTED: 100\n";
    cout << "ACTUAL: " << f.capacity() << endl;
    assert(100 == f.capacity());

    // DynamicArray::operator[ ] setter
    cout << "\nTesting the DynamicArray::operator[ ] setter\n";
    f[6] = "six";
    f[7] = "seven";
    f[-1000] = "back";
    cout << "\nTesting DynamicArray::operator[ ] setter\n";
    cout << "EXPECTED: six for a[6]\n";
    cout << "ACTUAL: " << f[6] << endl;
    assert("six" == f[6]);
    cout << "EXPECTED: seven for a[7]\n";
    cout << "ACTUAL: " << f[7] << endl;
    assert("seven" == f[7]);
    cout << "EXPECTED: back for a[-1000]\n";
    cout << "ACTUAL: " << f[-1000] << endl;
    assert("back" == f[-1000]);

    // DynamicArray::operator[ ] getter
    cout << "\nTesting the DynamicArray::operator[ ] getter\n";
    const DynamicArray<string> g = f;
    for (int i = 0; i < g.capacity(); i++) {
        assert(f[i] == g[i]);
    }

    // const object test
    cout << "\nConst object test\n";
    const DynamicArray<string> h(100);
    assert(h.capacity());
    assert(h[0] == h[0]);
    assert(h[-1] == h[-1]);

    // object copy test
    cout << "\nObject copy test\n";
    DynamicArray<string> j = f;
    assert(f.capacity() == j.capacity());
    for (int i = 0; i < f.capacity(); i++) {
        assert(f[i] == j[i]);
    }

    // object assignment test
    cout << "\nObject assignment test\n";
    DynamicArray<string> k; k = f;
    assert(f.capacity() == k.capacity());
    for (int i = 0; i < f.capacity(); i++) {
        assert(f[i] == k[i]);
    }

    return 0;
}