//
// Created by Khemin on 25-11-2021.
//

#ifndef AP_PROJECT_2021_2022_ABSTRACTFACTORY_H
#define AP_PROJECT_2021_2022_ABSTRACTFACTORY_H

#include "Player.h"
#include "Platform.h"
#include "Bonus.h"
#include "Background.h"

/// Abstract interface to create Entities in the world.
class AbstractFactory {
public:
    virtual Player createPlayer() = 0;
    virtual Platform createPlatform(float x, float y, const std::pair<bool, Bonus>& b) = 0;
    virtual Background createBackground(float y, std::string bgType) = 0;
    virtual Bonus createBonus(float x, float y) = 0;
};


#endif //AP_PROJECT_2021_2022_ABSTRACTFACTORY_H
