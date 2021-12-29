//
// Created by Khemin on 18-11-2021.
//

#ifndef AP_PROJECT_2021_2022_STOPWATCH_H
#define AP_PROJECT_2021_2022_STOPWATCH_H

#include <chrono>
#include <memory>

/// Singleton class that measures time.
class Stopwatch {
    static std::shared_ptr<Stopwatch> instance;

    std::chrono::time_point<std::chrono::steady_clock> start;
    Stopwatch();

public:
    /// Returns the singleton instance or creates a new one if it's invoked the first time.
    /// \return shared_prt<Stopwatch> the singleton Stopwatch instance
    static std::shared_ptr<Stopwatch> getInstance();

    /// Returns the elapsed time since last reset in millisecons(ms)
    /// \return long long int : elapsed time in ms
    long long int timeInMilliseconds();

    /// Resets the stopwatch and returns the elapsed time in milliseconds since last reset.
    /// \return long long int : elapsed time in ms
    long long int reset();
};


#endif //AP_PROJECT_2021_2022_STOPWATCH_H
