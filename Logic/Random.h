//
// Created by Khemin on 18-11-2021.
//

#ifndef AP_PROJECT_2021_2022_RANDOM_H
#define AP_PROJECT_2021_2022_RANDOM_H

#include <cstdlib>
#include <ctime>
#include <memory>

/// Singleton Class that can generate (pseudo-)random numbers.
class Random {
    static std::shared_ptr<Random> instance;
    Random();
public:
    /// Returns the singleton instance or creates a new one if it's invoked the first time.
    /// \return shared_prt<Random> the singleton Random instance
    static std::shared_ptr<Random> getInstance();

    /// Returns a (pseudo-)random integer between the given min and max values.
    /// \param min : int : minimum value
    /// \param max : int : maximum value
    /// \return integer : the (pseudo-)random generated integer
    static int randInt(int min, int max);

    /// Returns a (pseudo-)random float between the given min and max values.
    /// \param min : float : minimum value
    /// \param max : float : maximum value
    /// \return integer : the (pseudo-)random generated float
    static float randFloat(float min, float max);

};


#endif //AP_PROJECT_2021_2022_RANDOM_H
