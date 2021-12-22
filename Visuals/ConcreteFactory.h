//
// Created by Khemin on 25-11-2021.
//

#ifndef AP_PROJECT_2021_2022_CONCRETEFACTORY_H
#define AP_PROJECT_2021_2022_CONCRETEFACTORY_H

#include "../Logic/AbstractFactory.h"
#include "PlayerView.h"
#include "PlatformView.h"
#include "BonusView.h"
#include "BackgroundView.h"
#include "TextureLoader.h"
#include "../Logic/Random.h"

class ConcreteFactory : public AbstractFactory {
    std::map<std::string, sf::Texture> textures;
public:
    ConcreteFactory();
    Player createPlayer() override;
    Platform createPlatform(float x, float y, float heightInWorld, const std::pair<bool, Bonus>& b) override;
    Background createBackground(float y, std::string bgType) override;
    Bonus createBonus(float x, float y) override;
};


#endif //AP_PROJECT_2021_2022_CONCRETEFACTORY_H
