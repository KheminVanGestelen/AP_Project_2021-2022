//
// Created by Khemin on 25-11-2021.
//

#ifndef AP_PROJECT_2021_2022_ABSTRACTFACTORY_H
#define AP_PROJECT_2021_2022_ABSTRACTFACTORY_H

#include "Player.h"
#include "Platform.h"
#include "Bonus.h"

class AbstractFactory {

public:
    virtual Player createPlayer() = 0;
    virtual Platform createPlatform(float x, float y, float heightInWorld) = 0;
//    virtual Bonus createBonus() = 0;
};


#endif //AP_PROJECT_2021_2022_ABSTRACTFACTORY_H
