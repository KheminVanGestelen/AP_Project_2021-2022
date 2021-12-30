//
// Created by Khemin on 25-11-2021.
//

#ifndef AP_PROJECT_2021_2022_PLAYERVIEW_H
#define AP_PROJECT_2021_2022_PLAYERVIEW_H

#include "EntityView.h"

/// Class that models the visual representation of the Player character.
/// \param frameCounter : int : a counter to slow down the visual updates of the Player's frame texture. Only applies to the rocket sf::Sprite.
/// \param rocket : sf::Sprite : An SFML Sprite that visualizes the Player when he is in a Rocket.
class PlayerView : public EntityView {
    int frameCounter;
public:
    sf::Sprite rocket;

    PlayerView();
    explicit PlayerView(const sf::Texture& texture, const sf::Texture &rocketTexture);
    PlayerView(const sf::Texture& texture, const sf::Texture &rocketTexture,
               const sf::IntRect& rect, const sf::IntRect& rect2);

    /// Updates the visual frame texture of the PlayerView to correspond to the Player's state in the world.
    /// \param ySpeed : float : vertical movement speed of the Player character.
    /// \param movingLeft : bool : true if the Player is moving to the left, false otherwise
    /// \param movingRight : bool : true if the Player is moving to the right, false otherwise
    void update(float ySpeed, bool movingLeft, bool movingRight);

    /// Changes the position of both the rocket and the sprite attributes to newPos. The position lies within the window's coordinate system
    /// (origin in the top left corner of the window).
    /// \param newPos : pair<float, float> : new position to set
    void setSpritePos(std::pair<float, float> newPos) override;

};


#endif //AP_PROJECT_2021_2022_PLAYERVIEW_H
