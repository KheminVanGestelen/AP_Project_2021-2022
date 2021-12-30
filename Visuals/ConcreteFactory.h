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

/// Class that implements the AbstractFactory interface. Used to create new Entities in the world.
/// \param textures : map<string, sf::Texture> : map with all usable Textures. Obtained from the TextureLoader singleton instance.
class ConcreteFactory : public AbstractFactory {
    std::map<std::string, sf::Texture> textures;
public:
    ConcreteFactory();

    /// Creates a new Player.
    /// \return Player : newly created player.
    Player createPlayer() override;

    /// Creates a new Platform.
    /// \param x : float : x position of the Platform in the world
    /// \param y : float : y position of the Platform in the world
    /// \param b : pair<bool, Bonus> : contains the Bonus that is present on the Platform. The boolean indicates wether the Bonus is valid and usable (true) or not (false).
    /// \return Platform : newly generated Platform
    Platform createPlatform(float x, float y, const std::pair<bool, Bonus>& b) override;

    /// Creates a new Background element.
    /// \param y : float : y position of the Background element in the world
    /// \param bgType : string : type of the Background element
    /// \return Background : newly created background element
    Background createBackground(float y, std::string bgType) override;

    /// Creates a new Bonus.
    /// \param x : float : x position of the Bonus in the world
    /// \param y : float : y position of the Bonus in the world
    /// \return Bonus : newly created Bonus
    Bonus createBonus(float x, float y) override;
};


#endif //AP_PROJECT_2021_2022_CONCRETEFACTORY_H
