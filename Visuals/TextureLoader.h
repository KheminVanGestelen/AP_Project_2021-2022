//
// Created by Khemin on 1-12-2021.
//

#ifndef AP_PROJECT_2021_2022_TEXTURELOADER_H
#define AP_PROJECT_2021_2022_TEXTURELOADER_H

#include <map>
#include <string>
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

//Decided to make this class a singleton. This way the textures only have to be loaded in from files once. They will
//be manipulated further by making use of sprites.
class TextureLoader {
    static std::shared_ptr<TextureLoader> instance;
    std::map<std::string, sf::Texture> textureMap;

    TextureLoader();
public:
    static std::shared_ptr<TextureLoader> getInstance();
    std::map<std::string, sf::Texture> textures();

};


#endif //AP_PROJECT_2021_2022_TEXTURELOADER_H
