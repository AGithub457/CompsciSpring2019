// Programmer: Armand Agopian
// Programmer's ID: 1612964

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

#include "DynamicArray.h"

struct Term
{
    string term;
    int indexUniqueSections;
    DynamicArray<string> sectionArr;
};

int main() {
    cout << "Programmer: Armand Agopian" << endl;
    cout << "Programmer's ID: 1612964" << endl;
    cout << "File: " << __FILE__ << endl << endl;

    ifstream fin;
    string row;
    string semester, year, term, section, course, courseCode;
    int indexUniqueTerms = 0;
    DynamicArray<Term> termArr;
    DynamicArray<string> courseCodeArr;
    DynamicArray<int> courseCodeCount;
    int indexUniqueCode = 0;

    int duplicate = 0;

    int counter = 0;

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
        for(i = 0; i < termArr.capacity(); i++) {
            if (termArr[i].term == term) {
                break;
            }
        }

        if(!(i < termArr.capacity())) {
            termArr[indexUniqueTerms].term = term;
            i = indexUniqueTerms;
            indexUniqueTerms++;
        }

        int j;
        for(j = 0; j < termArr[i].sectionArr.capacity(); j++) {
            if(termArr[i].sectionArr[j] == section) {
                duplicate++;
                break;
            }
        }

        if(!(j < termArr[i].sectionArr.capacity())) {
            termArr[i].sectionArr[j] = section;
            j = termArr[i].indexUniqueSections;
            termArr[i].indexUniqueSections++;
        }

        int k;
        for(k = 0; k < courseCodeArr.capacity(); k++) {
            if(courseCodeArr[k] == courseCode) {
                break;
            }
        }

        if(k < courseCodeArr.capacity()) {
            courseCodeCount[k]++;
        } else {
            courseCodeArr[indexUniqueCode] = courseCode;
            courseCodeCount[indexUniqueCode]++;
            indexUniqueCode++;
        }

        counter++;
        if(counter % 200 == 0) {
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