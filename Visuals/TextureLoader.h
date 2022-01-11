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

/// Singleton Class that loads all textures from file upon creation.
/// \param instance : shared_ptr<TextureLoader> : the singleton Class instance
/// \param textureMap : map<string, sf::Texture> : map with all the loaded Textures
///
///Decided to make this class a singleton. This way the textures only have to be loaded in from files once. They will
///be manipulated further by making use of sprites.
class TextureLoader {
    static std::shared_ptr<TextureLoader> instance;
    std::map<std::string, sf::Texture> textureMap;

    TextureLoader();
public:
    /// Returns the singleton instance or creates a new one if it's invoked the first time.
    /// \return shared_prt<TextureLoader> the singleton TextureLoader instance
    static std::shared_ptr<TextureLoader> getInstance();

    /// Getter for the textureMap attribute
    /// \return map<string, sf::Texture> : textureMap
    std::map<std::string, sf::Texture> textures() const;

};


#endif //AP_PROJECT_2021_2022_TEXTURELOADER_H
