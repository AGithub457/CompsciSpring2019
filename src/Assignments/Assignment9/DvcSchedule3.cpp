// Programmer: Armand Agopian
// Programmer's ID: 1612964
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <queue>

using namespace std;

#include "AssociativeArray.h"
#include "DynamicArray.h"

int main() {
    cout << "Programmer: Armand Agopian" << endl;
    cout << "Programmer's ID: 1612964" << endl;
    cout << "File: " << __FILE__ << endl << endl;

    ifstream fin;
    string row;
    string semester, year, term, section, course, courseCode, courseNumber;

    AssociativeArray<string, AssociativeArray<string, bool>> alreadySeen;
    AssociativeArray<string, AssociativeArray<string, int >> subjectCounts;

    int duplicate = 0;

    fin.open("dvc-schedule.txt");
    getline(fin, row);
    while (getline(fin, row)) {
        stringstream(row) >> semester >> year >> section >> course;
        term = semester + " " + year;
        stringstream ss(course);
        getline(ss, courseCode, '-');
        getline(ss, courseNumber);

        if(!alreadySeen[term][section]) {
            alreadySeen[term][section] = true;
            subjectCounts[courseCode][courseNumber]++;
        } else {
            duplicate++;
        }
    }

    cout << endl;
    cout << "DUPLICATES: " << duplicate << endl << endl;

    queue<string> subjectKeys = subjectCounts.keys();
    DynamicArray<string> subjects(subjectCounts.size());
    for(int i = 0; !subjectKeys.empty(); i++) {
        subjects[i] = subjectKeys.front();
        subjectKeys.pop();
    }

    for (int i = 0; i < subjects.capacity(); i++) {
        for (int j = i + 1; j < subjects.capacity(); j++) {
            if (subjects[j] < subjects[i]) {
                swap(subjects[i], subjects[j]);
            }
        }
    }

    for(int i = 0; i < subjects.capacity(); i++) {
        queue<string> courseKeys = subjectCounts[subjects[i]].keys();
        DynamicArray<string> courses(subjectCounts[subjects[i]].size());
        for(int j = 0; !courseKeys.empty(); j++) {
            courses[j] = courseKeys.front();
            courseKeys.pop();
        }

        for(int j = 0; j < courses.capacity(); j++) {
            for (int k = j + 1; k < courses.capacity(); k++) {
                if (courses[k] < courses[j]) {
                    swap(courses[j], courses[k]);
                }
            }
        }

        cout << subjects[i] << ", " << subjectCounts[subjects[i]].size() << " course(s)" << endl;
        for(int j = 0; j < courses.capacity(); j++) {
            cout << "\t" << subjects[i] << "-" << courses[j] << ", " << subjectCounts[subjects[i]][courses[j]] << " section(s)" << endl;
        }
        cout << endl;
    }
    return 0;
}