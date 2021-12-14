//
// Created by Khemin on 18-11-2021.
//

#ifndef AP_PROJECT_2021_2022_CAMERA_H
#define AP_PROJECT_2021_2022_CAMERA_H

#include <utility>
#include "Entity.h"
#include <cmath>

class Camera {
    float camWidth;
    float camHeight;
    float camCenterHeight;
    float camBottom;
public:
    Camera();
    Camera(float w, float h);

    float width() const;
    float height() const;
    float centerHeight() const;
    float bottomHeight() const;
    void setCenterHeight(float c);

    std::pair<float, float> getWindowCoord(const Entity& e) const;

    void update(float playerHeight);

};


#endif //AP_PROJECT_2021_2022_CAMERA_H
