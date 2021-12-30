//
// Created by Khemin on 25-11-2021.
//

#ifndef AP_PROJECT_2021_2022_ENTITYVIEW_H
#define AP_PROJECT_2021_2022_ENTITYVIEW_H

#include "../Logic/Observer.h"
#include "SFML/Graphics.hpp"

/// Class that models the visual representation for an Entity in the world
/// \param sprite : sf::Sprite : An SFML Sprite that visualizes the Entity
class EntityView : public Observer {
public:
    sf::Sprite sprite;

    EntityView();
    explicit EntityView(const sf::Texture& texture);
    EntityView(const sf::Texture& texture, const sf::IntRect& rect);

    /// Changes the position of the sprite attribute to newPos. The position lies within the window's coordinate system
    /// (origin in the top left corner of the window).
    /// \param newPos : pair<float, float> : new position of sprite
    virtual void setSpritePos(std::pair<float, float> newPos);
};


#endif //AP_PROJECT_2021_2022_ENTITYVIEW_H
