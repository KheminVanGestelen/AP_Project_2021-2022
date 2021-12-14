//
// Created by Khemin on 24-11-2021.
//

#include "Vector2D.h"

Vector2D::Vector2D(float x, float y) : x(x), y(y){}

float Vector2D::X() const {
    return x;
}

float Vector2D::Y() const {
    return y;
}

Vector2D Vector2D::operator+(Vector2D& right) const {
    float resultX = this->X() + right.X();
    float resultY = this->Y() + right.Y();

    return {resultX, resultY};
}

Vector2D Vector2D::operator-(Vector2D& right) const {
    float resultX = this->X() - right.X();
    float resultY = this->Y() - right.Y();

    return {resultX, resultY};
}

void Vector2D::operator+=(std::pair<float, float> right) {
    x += right.first;
    y += right.second;
}

void Vector2D::operator-=(std::pair<float, float> right) {
    x -= right.first;
    y -= right.second;
}

void Vector2D::operator+=(Vector2D& right) {
    x += right.X();
    y += right.Y();
}

void Vector2D::operator-=(Vector2D& right) {
    x -= right.X();
    y -= right.Y();
}

Vector2D Vector2D::operator*(float scalar) const {
    float resultX = this->X() * scalar;
    float resultY = this->Y() * scalar;

    return {resultX, resultY};
}

Vector2D operator*(float scalar, Vector2D vect) {
    float resultX = scalar * vect.X();
    float resultY = scalar * vect.Y();

    return {resultX, resultY};
}

void Vector2D::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
}


