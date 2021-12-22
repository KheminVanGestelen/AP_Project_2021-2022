//
// Created by Khemin on 18-11-2021.
//

#include "Platform.h"

Platform::Platform() : Entity(0.0, 0.0, 1.0, 1.0) , view(PlatformView()), bonus(Bonus()){
    visible = true;
    usableBonus = false;

    fragile = false;
    movingHorizontal = false;
    movingVertical = false;

    horizontalRange = {0.0, 0.0};
    verticalRange = {0.0, 0.0};

    baseSpeed = 0.0;

    xSpeed = 0.0;
    ySpeed = 0.0;
}

Platform::Platform(float x, float y, float w, float h, PlatformView plView,
                   float heightInWorld, const std::pair<bool, Bonus>& b) : Entity(x, y, w, h) , view(std::move(plView)), bonus(b.second){
    visible = true;
    usableBonus = b.first;

    int r1 = Random::getInstance()->randInt(0, 100);
    if (r1 >= 70 && r1 < 80 && heightInWorld > 5000) {
        fragile = false;
        movingHorizontal = true;
        movingVertical = false;
    }
    else if (r1 >= 80 && r1 < 90 && heightInWorld > 10000) {
        fragile = false;
        movingHorizontal = false;
        movingVertical = true;
    }
    else if (r1 >= 90 && r1 <= 100) {
        fragile = true;
        movingHorizontal = false;
        movingVertical = false;
    } else {
        fragile = false;
        movingHorizontal = false;
        movingVertical = false;
    }

    view.update(fragile, movingHorizontal, movingVertical);

    baseSpeed = 1.0;

    if (movingHorizontal) {
        horizontalRange = {x - 100.0, x + 100.0};
        xSpeed = baseSpeed;
    }
    else {
        horizontalRange = {0.0, 0.0};
        xSpeed = 0.0;
    }

    if (movingVertical) {
        verticalRange = {y - 100.0, y + 100.0};
        ySpeed = baseSpeed/2;
    }
    else {
        verticalRange = {0.0, 0.0};
        ySpeed = 0.0;
    }
}

bool Platform::hasUsableBonus() const {
    return usableBonus;
}

bool Platform::isVisible() const {
    return visible;
}

bool Platform::isFragile() const {
    return fragile;
}

bool Platform::isMovingHorizontal() const {
    return movingHorizontal;
}

bool Platform::isMovingVertical() const {
    return movingVertical;
}

float Platform::getYSpeed() const {
    return ySpeed;
}

std::pair<std::pair<float, float>, bool> Platform::getVerticalRange() const {
    return {verticalRange, movingVertical};
}

void Platform::setUsableBonus(bool b) {
    usableBonus = b;
}

void Platform::setVisible(bool b) {
    visible = b;
}

void Platform::update(float worldWidth) {
    Vector2D movement = Vector2D(0.0, 0.0);

    if(movingHorizontal || movingVertical) {
        movement += std::pair<float, float>(xSpeed, ySpeed);
        move(movement);
    }

    if (usableBonus)
        bonus.update(movement);

    if (movingHorizontal && (this->X() >= horizontalRange.second || this->X() + (this->getWidth()/2) >= worldWidth/2))
        xSpeed = -baseSpeed;
    if (movingHorizontal && (this->X() <= horizontalRange.first || this->X() - (this->getWidth()/2) <= -worldWidth/2))
        xSpeed = baseSpeed;

    if (movingVertical && this->Y() >= verticalRange.second)
        ySpeed = -baseSpeed;
    if (movingVertical && (this->Y() <= verticalRange.first || this->Y() <= 0.0))
        ySpeed = baseSpeed;

}