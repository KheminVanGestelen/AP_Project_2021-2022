//
// Created by Khemin on 25-11-2021.
//

#include "ConcreteFactory.h"

ConcreteFactory::ConcreteFactory() {
    textures = TextureLoader::getInstance()->textures();
}

Player ConcreteFactory::createPlayer() {
    sf::IntRect box = sf::IntRect(0,0,32,32);
    sf::IntRect box2 = sf::IntRect(0,0,32,48);
    PlayerView pView = PlayerView(textures["Player"], textures["MovingRocket"], box, box2);
    pView.sprite.scale(1.5, 1.5);
    pView.rocket.scale(1.5, 1.5);

    return {0.0, 0.0, 48.0, 48.0, pView};
}

Platform ConcreteFactory::createPlatform(float x, float y, float heightInWorld, const std::pair<bool, Bonus>& b) {
    sf::IntRect box = sf::IntRect(0,16,48,16);
    PlatformView plView = PlatformView(textures["Platform"], box);

    return {x, y, 48.0, 16.0, plView, heightInWorld, b};
}

Background ConcreteFactory::createBackground(float y, std::string bgType) {
    float mfact;
    if (bgType == "Background")
        mfact = -1.0;
    if (bgType == "StarsFar")
        mfact = 8.0;
    if (bgType == "StarsClose")
        mfact = 2.0;

    BackgroundView bgView = BackgroundView(textures[bgType]);

    return {0.0, y, 1024.0, 1024.0,bgView, mfact};
}

Bonus ConcreteFactory::createBonus(float x, float y) {
    int r1 = Random::getInstance()->randInt(0, 100);
    std::string bType;
    float width;
    float height;

    if (r1 < 10) {
        bType = "Rocket";
        width = 48.0;
        height = 48.0;
    } else {
        bType = "JumpPad";
        width = 48.0;
        height = 48.0;
    }

    sf::IntRect box = sf::IntRect(0,0,(int) width,(int) height);

    BonusView bView = BonusView(textures[bType], box);

    return {x, y, width, height, bView, bType};
}
