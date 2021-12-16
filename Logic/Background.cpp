//
// Created by Khemin on 18-11-2021.
//

#include "Background.h"

#include <utility>

Background::Background() : Entity(0.0, 0.5, 1.0, 1.0), view(BackgroundView()){
    movingBG = false;
    movementfactor = -1.0;
    ySpeed = 0.0;
}

Background::Background(float x, float y, float w, float h, BackgroundView bgView, float mfact) : Entity(x, y, w, h), view(std::move(bgView)){
    if (mfact >= 1.0)
        movingBG = true;
    else
        movingBG = false;
    movementfactor = mfact;
    ySpeed = 0.0;
}

float Background::getYSpeed() const {
    return ySpeed;
}

void Background::setYSpeed(float s) {
    ySpeed = s;
}

void Background::update(float camSpeed, float camBottomHeight) {
    Vector2D movement = Vector2D(0.0, 0.0);
    if (Y() + getHeight() <= camBottomHeight) {
        movement += std::pair<float, float>(0.0, 2 * getHeight());
    }
    movement += std::pair<float, float>(0.0, ySpeed);
    move(movement);

    if (camSpeed > 0.0 && movingBG) {
        ySpeed = -(camSpeed/movementfactor);
    } else {
        ySpeed = 0.0;
    }
}
