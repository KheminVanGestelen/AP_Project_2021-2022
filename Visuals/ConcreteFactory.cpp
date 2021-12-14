//
// Created by Khemin on 25-11-2021.
//

#include "ConcreteFactory.h"

ConcreteFactory::ConcreteFactory() {
    textures = TextureLoader::getInstance()->textures();
}

Player ConcreteFactory::createPlayer() {
    sf::IntRect box = sf::IntRect(0,0,32,32);
    PlayerView pView = PlayerView(textures["Player"], box);
    pView.sprite.scale(1.5, 1.5);

    return {0.0, 0.0, 48.0, 48.0, pView};
}

Platform ConcreteFactory::createPlatform(float x, float y, float heightInWorld) {
    sf::IntRect box = sf::IntRect(0,16,48,16);
    PlatformView plView = PlatformView(textures["Platform"], box);

    return {x, y, 48.0, 16.0, plView, heightInWorld};
}

//Bonus ConcreteFactory::createBonus() {}
