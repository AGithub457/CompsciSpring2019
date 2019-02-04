// Programmer: Armand Agopian
// Programmer's ID: 1612964

#include <fstream>

using namespace std;

int main() {
    ofstream fout;
    fout.open("excel.xls");

    fout << "Name\tAge\tGPA" << endl; // column headings
    fout << "Armand\t20\t3.742" << endl;
    
    fout.close();

    return 0;
}