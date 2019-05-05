// Programmer: Armand Agopian
// Programmer's ID: 1612964

#include <fstream>
#include <iostream>
#include <sstream>
#include <random>

using namespace std;

#include <ctime>
#include <cmath>
#include <cassert>

#include "DynamicArray.h"

int main() {
    cout << "Programmer: Armand Agopian" << endl;
    cout << "Programmer's ID: 1612964" << endl;
    cout << "File: " << __FILE__ << endl << endl;

    random_device rd;
    default_random_engine rng(rd());

    int n = 800, cycle = 0;
    double expected = 0;
    double firstValue = 0;
    double factor;

    for(; cycle < 4; cycle++, n *= 2) {
        DynamicArray<int> array(n);
        for(int i = 0; i < n; i++) {
            //Elkady
            uniform_int_distribution<int> distribution(1, n);
            int randomNum = distribution(rng);
            array[i] = randomNum;
        }

        clock_t startTime = clock();

        for(int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++){
                if (array[k] < array[j]) {
                    swap(array[j], array[k]);
                }
            }
        }

        for (int i = 1; i < n; i++) assert (array[i - 1] <= array[i]);

        clock_t endTime = clock();

        double elapsedSeconds = (double) (endTime - startTime) / CLOCKS_PER_SEC;

        factor = pow(2.0, double(cycle));
        expected = factor * factor * firstValue;

        cout << elapsedSeconds << " (expected " << expected << ") for n=" << n << endl;
    }

    return 0;
}