//
// Created by Khemin on 18-11-2021.
//

#include "Stopwatch.h"

Stopwatch::Stopwatch() : start(std::chrono::steady_clock::now()){}

std::shared_ptr<Stopwatch> Stopwatch::getInstance() {
    if (instance == nullptr)
        instance = std::make_shared<Stopwatch>(Stopwatch());
    return instance;
}

long long int Stopwatch::timeInMilliseconds() {
    auto now = std::chrono::steady_clock::now();

    return std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count();
}

long long int Stopwatch::reset() {
    long long int temp = this->timeInMilliseconds();

    start = std::chrono::steady_clock::now();
    return temp;
}
