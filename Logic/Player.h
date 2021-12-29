//
// Created by Khemin on 18-11-2021.
//

#ifndef AP_PROJECT_2021_2022_PLAYER_H
#define AP_PROJECT_2021_2022_PLAYER_H

#include "Entity.h"
#include "Vector2D.h"
#include "../Visuals/PlayerView.h"

/// Class that models the Player character in the world.
/// \param usingRocket : bool : true if the Player is inside a Rocket Bonus, false otherwise.
/// \param xSpeed : float : the horizontal movement speed of the Player.
/// \param ySpeed : float : the verictal movement speed of the Player.
/// \param baseYSpeed : float : the base value for the vertical movement speed of the Player. Determines how high a jump is.
/// \param movingLeft : bool : true if the Player is moving to the left, false otherwise.
/// \param movingRight : bool : true if the Player is moving to the right, false otherwise.
/// \param view : PlayerView : the visual respresentation of the Player character.
class Player : public Entity {
    bool usingRocket;

    float xSpeed;
    float ySpeed;
    float baseYSpeed;

    bool movingLeft;
    bool movingRight;
public:
    PlayerView view;

    Player();
    Player(float x, float y, float w, float h, PlayerView  pView);

    bool isMovingLeft() const;
    bool isMovingRight() const;
    bool isUsingRocket() const;

    void setMovingLeft(bool b);
    void setMovingRight(bool b);
    void setUsingRocket(bool b);

    float getYSpeed() const;
    void setYSpeed(float f);

    /// Makes the Player jump.
    void jump();

    /// Makes the Player use the Rocket Bonus.
    void enterRocket();

    /// Makes the Player Bounce on a Jump Pad Bonus.
    void bounce();

    /// Updates the Player.
    /// \param gravity : float : the world's gravity.
    void update(float gravity);
};


#endif //AP_PROJECT_2021_2022_PLAYER_H
