// Programmer: Armand Agopian
// Programmer's ID: 1612964

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

#include <ctime>
#include <cmath>

#include "DynamicArray.h"

int main() {
    cout << "Programmer: Armand Agopian" << endl;
    cout << "Programmer's ID: 1612964" << endl;
    cout << "File: " << __FILE__ << endl << endl;

    ifstream fin;
    string row;
    string semester, year, term, section, course, courseCode;
    DynamicArray<string> termArr;
    DynamicArray<string> sectionArr;
    int indexUniqueClass = 0;

    int duplicate = 0;

    int n = 800, cycle = 0, counter;
    double expected = 0;
    double firstValue = 0;
    double factor;

    for(; cycle < 4; cycle++, n *= 2) {
        clock_t startTime = clock();
        fin.open("dvc-schedule.txt");
        counter = 0;

        getline(fin, row);
        while (getline(fin, row) && counter < n) {
            stringstream(row) >> semester >> year >> section >> course;
            term = semester + " " + year;
            stringstream ss(course);
            getline(ss, courseCode, '-');

            int j;
            for (j = 0; j < sectionArr.capacity(); j++) {
                if ((sectionArr[j] == section) && (termArr[j] == term)) {
                    duplicate++;
                    break;
                }
            }

            if (j < sectionArr.capacity()) {

            } else {
                sectionArr[indexUniqueClass] = section;
                termArr[indexUniqueClass] = term;
                indexUniqueClass++;
            }
            counter++;
        }

        fin.close();
        clock_t endTime = clock();

        double elapsedSeconds = (double) (endTime - startTime) / CLOCKS_PER_SEC;

        factor = pow(2.0, double(cycle));
        expected = factor * factor * firstValue;

        cout << elapsedSeconds << " (expected " << expected << ") for n=" << n << endl;
    }

    return 0;
}