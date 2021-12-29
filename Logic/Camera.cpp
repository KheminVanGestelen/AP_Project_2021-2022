//
// Created by Khemin on 18-11-2021.
//

#include "Camera.h"

Camera::Camera() : camWidth(0.0), camHeight(0.0), camCenter(0.0), camBottom(0.0) , camSpeed(0.0){}

Camera::Camera(float w, float h) : camWidth(w), camHeight(h), camCenter(h / 2), camBottom(0.0), camSpeed(0.0){}

float Camera::width() const {
    return camWidth;
}

float Camera::height() const {
    return camHeight;
}

float Camera::centerHeight() const {
    return camCenter;
}

float Camera::bottomHeight() const {
    return camBottom;
}

float Camera::speed() const {
    return camSpeed;
}

std::pair<float, float> Camera::getWindowCoord(const Entity& e) const {
    std::pair<float, float> wCoord = {0,0};
    wCoord.first = (camWidth/2) + e.X() - (e.getWidth()/2);
    wCoord.second = (camHeight/2) - (e.Y() - camCenter) - e.getHeight();

    return wCoord;
}

void Camera::update(float playerHeight, float playerYSpeed) {
    camCenter += camSpeed;
    camBottom = camCenter - (camHeight / 2);

    if (playerHeight >= camCenter && playerYSpeed > 0){
        camSpeed = playerYSpeed;
    }
    if (playerHeight < camCenter) {
        camSpeed = 0.0;
    }
}

void Camera::reset() {
    camCenter = camHeight / 2;
    camBottom = 0.0;
    camSpeed = 0.0;
}
