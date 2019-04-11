// Programmer: Armand Agopian
// Programmer's ID: 1612964

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

#include "DynamicArray.h"

struct Term {
    string term;
    int numUniqueSections;
    DynamicArray<string> arrUniqueSections;
};

int main() {
    cout << "Programmer: Armand Agopian" << endl;
    cout << "Programmer's ID: 1612964" << endl;
    cout << "File: " << __FILE__ << endl << endl;

    ifstream fin;
    string row;
    string semester, year, term, section, course, courseCode;

    DynamicArray<Term> arrUniqueTerms;
    int numUniqueTerms = 0;

    DynamicArray<string> arrUniqueCourseCodes;
    DynamicArray<int> arrUniqueCourseCodeCounts;
    int numUniqueCourseCode = 0;

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


        bool foundTerm = false;
        int i = 0;
        for(; i < numUniqueTerms; i++) {
            if(arrUniqueTerms[i].term == term) {
                foundTerm = true;
                break;
            }
        }

        if(!foundTerm) {
            arrUniqueTerms[i].term = term;
            numUniqueTerms++;
        }

        bool foundSection = false;
        int j = 0;
        for(; j < arrUniqueTerms[i].numUniqueSections; j++) {
            if(arrUniqueTerms[i].arrUniqueSections[j] == section) {
                foundSection = true;
                break;
            }
        }

        if(!foundSection) {
            arrUniqueTerms[i].arrUniqueSections[j] = section;
            arrUniqueTerms[i].numUniqueSections++;

            bool foundCourseCode = false;
            int k = 0;
            for(; k < numUniqueCourseCode; k++) {
                if(arrUniqueCourseCodes[k] == courseCode) {
                    foundCourseCode = true;
                    break;
                }
            }

            if(!foundCourseCode) {
                arrUniqueCourseCodes[k] = courseCode;
                numUniqueCourseCode++;
            }

            arrUniqueCourseCodeCounts[k]++;
        } else {
            duplicate++;
        }
    }

    cout << endl;
    cout << "DUPLICATES: " << duplicate << endl << endl;

    for (int i = 0; i < numUniqueCourseCode; i++) {
        for (int j = i + 1; j < numUniqueCourseCode; j++) {
            if (arrUniqueCourseCodes[j] < arrUniqueCourseCodes[i]) {
                swap(arrUniqueCourseCodes[i], arrUniqueCourseCodes[j]);
                swap(arrUniqueCourseCodeCounts[i], arrUniqueCourseCodeCounts[j]);
            }
        }
    }

    for (int i = 0; i < numUniqueCourseCode; i++) {
        cout << arrUniqueCourseCodes[i] << ", " << arrUniqueCourseCodeCounts[i] << " sections" << endl;
    }
    return 0;
}