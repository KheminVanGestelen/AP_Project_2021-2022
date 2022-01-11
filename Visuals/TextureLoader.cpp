//
// Created by Khemin on 1-12-2021.
//

#include "TextureLoader.h"

TextureLoader::TextureLoader() {
    textureMap = std::map<std::string, sf::Texture>();

    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("../Assets/Player.png"))
        std::cerr << "Could not load player texture" << std::endl;
    else
        textureMap["Player"] = playerTexture;

    sf::Texture platformTexture;
    if (!platformTexture.loadFromFile("../Assets/Platform.png"))
        std::cerr << "Could not load platform texture" << std::endl;
    else
        textureMap["Platform"] = platformTexture;

    sf::Texture bonusTexture;
    if (!bonusTexture.loadFromFile("../Assets/JumpPadBonus.png"))
        std::cerr << "Could not load bonus texture" << std::endl;
    else
        textureMap["Bonus"] = bonusTexture;

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("../Assets/Background.png"))
        std::cerr << "Could not load background texture" << std::endl;
    else
        textureMap["Background"] = backgroundTexture;

    sf::Texture starsFarTexture;
    if (!starsFarTexture.loadFromFile("../Assets/StarsFar.png"))
        std::cerr << "Could not load texture for far stars" << std::endl;
    else
        textureMap["StarsFar"] = starsFarTexture;

    sf::Texture starsCloseTexture;
    if (!starsCloseTexture.loadFromFile("../Assets/StarsClose.png"))
        std::cerr << "Could not load texture for close stars " << std::endl;
    else
        textureMap["StarsClose"] = starsCloseTexture;

    sf::Texture movingRocketTexture;
    if (!movingRocketTexture.loadFromFile("../Assets/MovingRocket.png"))
        std::cerr << "Could not load texture for moving Rocket " << std::endl;
    else
        textureMap["MovingRocket"] = movingRocketTexture;

    sf::Texture rocketBonusTexture;
    if (!rocketBonusTexture.loadFromFile("../Assets/RocketBonus.png"))
        std::cerr << "Could not load texture for Rocket bonus" << std::endl;
    else
        textureMap["Rocket"] = rocketBonusTexture;

    sf::Texture jumpPadBonusTexture;
    if (!jumpPadBonusTexture.loadFromFile("../Assets/JumpPadBonus.png"))
        std::cerr << "Could not load texture for Jump Pad bonus" << std::endl;
    else
        textureMap["JumpPad"] = jumpPadBonusTexture;

    sf::Texture gameOverScreenTexture;
    if (!gameOverScreenTexture.loadFromFile("../Assets/GameOverScreen.png"))
        std::cerr << "Could not load texture for Game Over screen" << std::endl;
    else
        textureMap["GameOver"] = gameOverScreenTexture;
}

std::shared_ptr<TextureLoader> TextureLoader::getInstance() {
    if (instance == nullptr)
        instance = std::make_shared<TextureLoader>(TextureLoader());
    return instance;
}

std::map<std::string, sf::Texture> TextureLoader::textures() const{
    return textureMap;
}
