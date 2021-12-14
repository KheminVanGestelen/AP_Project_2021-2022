//
// Created by Khemin on 18-11-2021.
//

#include "Camera.h"

#include <cmath>

Camera::Camera() : camWidth(0.0), camHeight(0.0), camCenterHeight(0.0), camBottom(0.0) {}

Camera::Camera(float w, float h) : camWidth(w), camHeight(h), camCenterHeight(h/2), camBottom(0.0){}

float Camera::width() const {
    return camWidth;
}

float Camera::height() const {
    return camHeight;
}

float Camera::centerHeight() const {
    return camCenterHeight;
}

float Camera::bottomHeight() const {
    return camBottom;
}

void Camera::setCenterHeight(float c) {
    camCenterHeight = c;
}

std::pair<float, float> Camera::getWindowCoord(const Entity& e) const {
    std::pair<float, float> wCoord = {0,0};
    wCoord.first = (camWidth/2) + e.X() - (e.getWidth()/2);
    wCoord.second = (camHeight/2) - (e.Y() - camCenterHeight) - e.getHeight();

    return wCoord;
}

void Camera::update(float playerHeight) {
    if (playerHeight >= camCenterHeight){
        camCenterHeight = std::floor(playerHeight);
        camBottom = camCenterHeight - camHeight/2;
    }
}
