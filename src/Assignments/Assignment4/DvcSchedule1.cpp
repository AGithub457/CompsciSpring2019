// Programmer: Armand Agopian
// Programmer's ID: 1612964

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

#include "DynamicArray.h"

int main() {
    cout << "Programmer: Armand Agopian" << endl;
    cout << "Programmer's ID: 1612964" << endl;
    cout << "File: " << __FILE__ << endl << endl;

    ifstream fin;
    string row;
    string semester, year, term, section, course, courseCode;
    int counter = 0;
    DynamicArray<string> termArr;
    DynamicArray<string> sectionArr;
    int indexUniqueClass = 0;
    DynamicArray<string> courseCodeArr;
    DynamicArray<int> courseCodeCount;
    int indexUniqueCode = 0;

    int duplicate = 0;

    fin.open("dvc-schedule.txt");
    if (!fin) {
        throw "File not found";
    }
    getline(fin, row);
    while (getline(fin, row)) {
        stringstream(row) >> semester >> year >> section >> course;
        term = semester + " " + year;
        stringstream ss(course);
        getline(ss, courseCode, '-');

        int i;
        for(i = 0; i < sectionArr.capacity(); i++) {
            if ((sectionArr[i] == section) && (termArr[i] == term)) {
                duplicate++;
                break;
            }
        }

        if(i < sectionArr.capacity()) {

        } else {
            sectionArr[indexUniqueClass] = section;
            termArr[indexUniqueClass] = term;
            indexUniqueClass++;

            int j;
            for(j = 0; j < courseCodeArr.capacity(); j++) {
                if(courseCodeArr[j] == courseCode) {
                    break;
                }
            }

            if(j < courseCodeArr.capacity()) {
                courseCodeCount[j]++;
            } else {
                courseCodeArr[indexUniqueCode] = courseCode;
                courseCodeCount[indexUniqueCode]++;
                indexUniqueCode++;
            }
        }

        counter++;
        if(counter % 1000 == 0) {
            cout << '.'; cout.flush();
        }
    }

    cout << endl;
    cout << "DUPLICATES: " << duplicate << endl << endl;

    for (int i = 0; i < indexUniqueCode; i++) {
        for (int j = i + 1; j < indexUniqueCode; j++) {
            if (courseCodeArr[j] < courseCodeArr[i]) {
                swap(courseCodeArr[i], courseCodeArr[j]);
                swap(courseCodeCount[i], courseCodeCount[j]);
            }
        }
    }

    for (int i = 0; i < indexUniqueCode; i++) {
        cout << courseCodeArr[i] << ", " << courseCodeCount[i] << " sections" << endl;
    }
    return 0;
}