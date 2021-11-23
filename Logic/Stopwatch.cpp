//
// Created by Khemin on 18-11-2021.
//

#include "Stopwatch.h"

Stopwatch::Stopwatch() : start(chrono::steady_clock::now()){}

long long int Stopwatch::timeInSeconds() {
    auto now = chrono::steady_clock::now();

    return chrono::duration_cast<chrono::seconds>(now - start).count();
}

long long int Stopwatch::timeInMilliseconds() {
    auto now = chrono::steady_clock::now();

    return chrono::duration_cast<chrono::milliseconds>(now - start).count();
}

long long int Stopwatch::timeInMicroseconds() {
    auto now = chrono::steady_clock::now();

    return chrono::duration_cast<chrono::microseconds>(now - start).count();
}

long long int Stopwatch::reset() {
    long long int temp = this->timeInMilliseconds();

    start = chrono::steady_clock::now();
    return temp;
}
