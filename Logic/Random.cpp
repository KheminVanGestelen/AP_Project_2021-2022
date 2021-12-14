//
// Created by Khemin on 18-11-2021.
//

#include "Random.h"

Random::Random() {
    srand((unsigned) time(nullptr));
}

std::shared_ptr<Random> Random::getInstance() {
    if (instance == nullptr)
        instance = std::make_shared<Random>(Random());
    return instance;
}

int Random::randInt(int min, int max) {
    return rand() % (max - min) + min;
}

float Random::randFloat(float min, float max) {
    return min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(max-min)));
}
