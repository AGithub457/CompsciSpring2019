// Programmer: Armand Agopian
// Programmer's ID: 1612964

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include <cassert>

#include "Stack.h"
#include "Stack.h" //ifndef test

int main() {
    Stack<double> a;

    cout << "Stack test: (double)" << endl;
    cout << "--------------------" << endl;

    //Stack::size
    cout << endl << "Testing Stack::size" << endl;
    cout << "Expected: 0" << endl;
    cout << "Actual: " << a.size() << endl;
    assert(a.size() == 0);
    cout << "Pass!" << endl;

    //Stack::peek and Stack::push
    cout << endl << "Testing Stack::peek and Stack::push" << endl;
    a.push(1.1);
    cout << "Expected: 1.1" << endl;
    cout << "Actual: " << a.peek() << endl;
    assert(a.peek() == 1.1);
    cout << "Pass!" << endl;

    //Stack::pop
    cout << endl << "Testing Stack::pop" << endl;
    a.push(2.2);
    cout << "Before pop: 2.2" << endl;
    cout << "After pop: 1.1" << endl;
    a.pop();
    assert(a.peek() == 1.1);
    cout << "Pass!" << endl;

    //Copy constructor
    cout << endl << "Testing copy constructor" << endl;
    Stack<double> b = a;
    for(int i = 0; i < b.size(); i++) {
        assert(b.peek() == a.peek());
    }
    cout << "Pass!" << endl;

    //Assignment operator
    cout << endl << "Testing assignment operator" << endl;
    Stack<double> c;
    c = a;
    for(int i = 0; i < c.size(); i++) {
        assert(c.peek() == a.peek());
    }
    cout << "Pass!" << endl;

    //Stack::capacity
    cout << endl << "Testing Stack::capacity" << endl;
    Stack<double> d;
    for(int i = 0; i < 5; i++) {
        d.push(1.1);
    }
    cout << "Default capacity: 2" << endl;
    cout << "After pushing 5 values, size is now: " << d.size() << endl;
    assert(d.size() == 5);
    cout << "Pass!" << endl;

    //Stack::clear and Stack::empty
    cout << endl << "Testing Stack::clear and Stack:: empty" << endl;
    a.clear();
    assert(a.empty());
    cout << "Pass!" << endl;

    //Const object test
    cout << endl << "Testing constant object" << endl;
    const Stack<double> e;
    assert(e.empty() == e.empty());
    cout << "Pass!" << endl;

    Stack<string> f;

    cout << "Stack test: (string)" << endl;
    cout << "--------------------" << endl;

    //Stack::size
    cout << endl << "Testing Stack::size" << endl;
    cout << "Expected: 0" << endl;
    cout << "Actual: " << f.size() << endl;
    assert(f.size() == 0);
    cout << "Pass!" << endl;

    //Stack::peek and Stack::push
    cout << endl << "Testing Stack::peek and Stack::push" << endl;
    f.push("1.1");
    cout << "Expected: 1.1" << endl;
    cout << "Actual: " << f.peek() << endl;
    assert(f.peek() == "1.1");
    cout << "Pass!" << endl;

    //Stack::pop
    cout << endl << "Testing Stack::pop" << endl;
    f.push("2.2");
    cout << "Before pop: 2.2" << endl;
    cout << "After pop: 1.1" << endl;
    f.pop();
    assert(f.peek() == "1.1");
    cout << "Pass!" << endl;

    //Copy constructor
    cout << endl << "Testing copy constructor" << endl;
    Stack<string> g = f;
    for(int i = 0; i < g.size(); i++) {
        assert(g.peek() == f.peek());
    }
    cout << "Pass!" << endl;

    //Assignment operator
    cout << endl << "Testing assignment operator" << endl;
    Stack<string> h;
    h = f;
    for(int i = 0; i < h.size(); i++) {
        assert(h.peek() == f.peek());
    }
    cout << "Pass!" << endl;

    //Stack::capacity
    cout << endl << "Testing Stack::capacity" << endl;
    Stack<string> j;
    for(int i = 0; i < 5; i++) {
        j.push("1.1");
    }
    cout << "Default capacity: 2" << endl;
    cout << "After pushing 5 values, size is now: " << j.size() << endl;
    assert(j.size() == 5);
    cout << "Pass!" << endl;

    //Stack::clear and Stack::empty
    cout << endl << "Testing Stack::clear and Stack:: empty" << endl;
    f.clear();
    assert(f.empty());
    cout << "Pass!" << endl;

    //Const object test
    cout << endl << "Testing constant object" << endl;
    const Stack<double> k;
    assert(k.empty() == k.empty());
    cout << "Pass!" << endl;

    return 0;
}