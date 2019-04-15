// Programmer: Armand Agopian
// Programmer's ID: 1612964

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

#include "Queue.h"
#include <cmath>
#include <cstdlib>

struct Customer {
    char id;
    int arrivalTime, serviceEndTime;

};

int getRandomNumberOfArrivals(double averageArrivalRate) {
    int arrivals = 0;
    double probOfnArrivals = exp(-averageArrivalRate);
    for (double randomValue = (double)rand( ) / RAND_MAX;
         (randomValue -= probOfnArrivals) > 0.0;
         probOfnArrivals *= averageArrivalRate / static_cast<double>(++arrivals));
    return arrivals;
}

int main() {
    cout << "Programmer: Armand Agopian" << endl;
    cout << "Programmer's ID: 1612964" << endl;
    cout << "File: " << __FILE__ << endl << endl;

    string input;
    ifstream fin;
    int numServers = 0;
    double arrivalRate = 0;
    int maxQueue = 0;
    int minService = 0;
    int maxService = 0;
    int maxClock = 0;
    int totalPeople = 0;
    int numCustomers = 0;

    Queue<Customer> customers;
    DynamicArray<bool> isBusy;
    DynamicArray<Customer> nowWorking;

    fin.open("simulation.txt");
    if (!fin) {
        throw "File not found";
    }
    getline(fin, input);
    stringstream(input) >> numServers;
    getline(fin, input);
    stringstream(input) >> arrivalRate;
    getline(fin, input);
    stringstream(input) >> maxQueue;
    getline(fin, input);
    stringstream(input) >> minService;
    getline(fin, input);
    stringstream(input) >> maxService;
    getline(fin, input);
    stringstream(input) >> maxClock;

    cout << "number of servers:     " << numServers << endl;
    cout << "customer arrival rate: " << arrivalRate << " per minute, for " << maxClock << " minutes" << endl;
    cout << "maximum queue length:  " << maxQueue << endl;
    cout << "minimum service time:  " << minService << " minutes" << endl;
    cout << "maximum service time:  " << maxService << " minutes" << endl;

    for (int time = 0; time < maxClock; time++) {
        for(int j = 0; j < numServers; j++) {
            if(isBusy[j] == true) {
                if(j == nowWorking[i].serviceEndTime) {
                    isBusy[j] = false;
                }
            }
        }

        if(time < minService) {
            Customer a;
            a.id = (numCustomers % 26) + 65;
            a.arrivalTime = getRandomNumberOfArrivals(arrivalRate);
            customers.push(a);
            numCustomers++;
        }

        cout << "Time: " << time << endl;
        cout << "----------------------------\n";
        cout << "server now serving wait line\n";
        cout << "------ ----------- ---------\n";

        for (int i = 0; i < numServers; i++) {
            cout << "  " << i + 1;
            if (isBusy[i]) {
                cout << "          " << nowWorking[i].IDtag;
            } else if (i == 0 && customers.size() != 0) {

            }
            cout << endl;
        }
    }
}