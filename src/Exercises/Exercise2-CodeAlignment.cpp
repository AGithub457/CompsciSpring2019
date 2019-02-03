// Programmer: Armand Agopian
// Programmer's ID: 1612964

#include <string>

using namespace std;

void one(int, string);

int main() {
    one(1, "test");

    return 0;
}

void one(int val, string name) {
    name += val;
}