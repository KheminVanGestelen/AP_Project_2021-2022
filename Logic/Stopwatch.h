//
// Created by Khemin on 18-11-2021.
//

#ifndef AP_PROJECT_2021_2022_STOPWATCH_H
#define AP_PROJECT_2021_2022_STOPWATCH_H

#include <chrono>

using namespace std;

class Stopwatch {

    std::chrono::time_point<std::chrono::steady_clock> start;

public:
    Stopwatch();
    long long int timeInSeconds();
    long long int timeInMilliseconds();
    long long int timeInMicroseconds();
    long long int reset();


};


#endif //AP_PROJECT_2021_2022_STOPWATCH_H
