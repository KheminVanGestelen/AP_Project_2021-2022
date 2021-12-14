//
// Created by Khemin on 18-11-2021.
//

#ifndef AP_PROJECT_2021_2022_PLAYER_H
#define AP_PROJECT_2021_2022_PLAYER_H

#include "Entity.h"
#include "Vector2D.h"
#include "../Visuals/PlayerView.h"

class Player : public Entity {
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

    void setMovingLeft(bool b);
    void setMovingRight(bool b);

    float getYSpeed() const;
    void setYSpeed(float f);

    void move(Vector2D m);
    void jump();
    void update(float gravity);
};


#endif //AP_PROJECT_2021_2022_PLAYER_H
