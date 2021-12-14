//
// Created by Khemin on 18-11-2021.
//

#include "Entity.h"

Entity::Entity(float x, float y, float w, float h) : x(x), y(y), width(w), height(h){}

float Entity::X() const {
    return x;
}

float Entity::Y() const {
    return y;
}

float Entity::getWidth() const {
    return width;
}

float Entity::getHeight() const {
    return height;
}

void Entity::setX(float i) {
    x = i;
}

void Entity::setY(float i) {
    y = i;
}
