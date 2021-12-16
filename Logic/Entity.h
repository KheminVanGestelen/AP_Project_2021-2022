//
// Created by Khemin on 18-11-2021.
//

#ifndef AP_PROJECT_2021_2022_ENTITY_H
#define AP_PROJECT_2021_2022_ENTITY_H

#include <utility>
#include "Vector2D.h"

class Entity {
    float x;
    float y;
    float width;
    float height;
public:
    Entity(float x, float y, float w, float h);

    float X() const;
    float Y() const;
    float getWidth() const;
    float getHeight() const;

    void setX(float i);
    void setY(float i);

    void move(Vector2D m);
};


#endif //AP_PROJECT_2021_2022_ENTITY_H
