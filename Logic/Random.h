//
// Created by Khemin on 18-11-2021.
//

#ifndef AP_PROJECT_2021_2022_RANDOM_H
#define AP_PROJECT_2021_2022_RANDOM_H

#include <cstdlib>
#include <ctime>
#include <memory>

class Random {
    static std::shared_ptr<Random> instance;
    Random();
public:
    static std::shared_ptr<Random> getInstance();

    static int randInt(int min, int max);
    static float randFloat(float min, float max);

};


#endif //AP_PROJECT_2021_2022_RANDOM_H
