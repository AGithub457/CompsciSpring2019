// Programmer: Armand Agopian
// Programmer's ID: 1612964

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

#include <ctime>

int main() {
    cout << "Programmer: Armand Agopian" << endl;
    cout << "Programmer's ID: 1612964" << endl;
    cout << "File: " << __FILE__ << endl << endl;

    ifstream fin;
    string row, semester, year, term, section, course, courseCode;
    int n = 8000;

    for(int i = 0; i < 4; i++, n *= 2) {
        clock_t startTime = clock();
        fin.open("dvc-schedule.txt");
        getline(fin, row);
        for (int j = 0; j < n; j++) {
            getline(fin, row);
            stringstream(row) >> semester >> year >> section >> course;
        }
        fin.close();
        clock_t endTime = clock();
        double elapsedSeconds = (double) (endTime - startTime) / CLOCKS_PER_SEC;
        cout << elapsedSeconds << " (expected) for n=" << n << endl;
    }

    return 0;
}