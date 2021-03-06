//
// Created by Khemin on 18-11-2021.
//

#include "Player.h"

#include <utility>

Player::Player() : Entity(0.0, 0.0, 1.0, 1.0){
    usingRocket = false;

    xSpeed = 0.0;
    ySpeed = 0.0;
    baseYSpeed = 0.0;

    movingLeft = false;
    movingRight = false;
}

Player::Player(float x, float y, float w, float h, PlayerView  pView) : Entity(x, y, w, h), view(std::move(pView)){
    usingRocket = false;

    xSpeed = 4.0;
    ySpeed = 0.0;
    baseYSpeed = 8.5;

    movingLeft = false;
    movingRight = false;
}

bool Player::isMovingLeft() const {
    return movingLeft;
}

bool Player::isMovingRight() const {
    return movingRight;
}

bool Player::isUsingRocket() const {
    return usingRocket;
}

void Player::setMovingLeft(bool b) {
    movingLeft = b;
}

void Player::setMovingRight(bool b) {
    movingRight = b;
}

void Player::setUsingRocket(bool b) {
    usingRocket = b;
}

float Player::getYSpeed() const {
    return ySpeed;
}

void Player::setYSpeed(float f) {
    ySpeed = f;
}

void Player::jump() {
    ySpeed = baseYSpeed;
}

void Player::enterRocket() {
    usingRocket = true;
    ySpeed = 85;
}

void Player::bounce() {
    ySpeed = 2*baseYSpeed;
}

void Player::update(float gravity) {
    Vector2D movement = Vector2D(0.0, 0.0);
    if (usingRocket && ySpeed < 5.0) {
        usingRocket = false;
    }

    if (!usingRocket ) {
        if (movingLeft)
            movement -= std::pair<float, float>(xSpeed, 0.0);
        if (movingRight)
            movement += std::pair<float, float>(xSpeed, 0.0);
    }
    movement += std::pair<float, float>(0.0,ySpeed);

    move(movement);
    ySpeed -= gravity;

    view.update(ySpeed, movingLeft, movingRight);
}
