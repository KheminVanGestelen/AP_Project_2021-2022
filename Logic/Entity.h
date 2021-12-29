//
// Created by Khemin on 18-11-2021.
//

#ifndef AP_PROJECT_2021_2022_ENTITY_H
#define AP_PROJECT_2021_2022_ENTITY_H

#include <utility>
#include "Vector2D.h"

/// Class that models an Entity in the world.
/// \param x : float : the x position of the Entity in the world.
/// \param y : float : the y position of the Entity in the world.
/// \param width : float : the width of the Entity
/// \param height : float : the height of the Entity
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

    /// Moves the Entity over the given 2D vector.
    /// \param m : Vector2D : the vector over which the Bonus is moved.
    void move(Vector2D m);
};


#endif //AP_PROJECT_2021_2022_ENTITY_H
