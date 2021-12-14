//
// Created by Khemin on 1-12-2021.
//

#include "TextureLoader.h"

TextureLoader::TextureLoader() {
    textureMap = std::map<std::string, sf::Texture>();

    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("Assets/Player.png"))
        std::cerr << "Could not load player texture" << std::endl;
    else
        textureMap["Player"] = playerTexture;

    sf::Texture platformTexture;
    if (!platformTexture.loadFromFile("Assets/Platform.png"))
        std::cerr << "Could not load platform texture" << std::endl;
    else
        textureMap["Platform"] = platformTexture;

    sf::Texture bonusTexture;
    if (!bonusTexture.loadFromFile("Assets/Bonus.png"))
        std::cerr << "Could not load bonus texture" << std::endl;
    else
        textureMap["Bonus"] = bonusTexture;
}

std::shared_ptr<TextureLoader> TextureLoader::getInstance() {
    if (instance == nullptr)
        instance = std::make_shared<TextureLoader>(TextureLoader());
    return instance;
}

std::map<std::string, sf::Texture> TextureLoader::textures() {
    return textureMap;
}
