//
// Created by Khemin on 24-11-2021.
//

#ifndef AP_PROJECT_2021_2022_VECTOR2D_H
#define AP_PROJECT_2021_2022_VECTOR2D_H

#include <utility>

class Vector2D {
    float x;
    float y;
public:
    Vector2D(float x, float y);

    float X() const;
    float Y() const;


    Vector2D operator+(Vector2D& right) const;
    Vector2D operator-(Vector2D& right) const;
    void operator+=(std::pair<float, float> right);
    void operator-=(std::pair<float, float> right);
    void operator+=(Vector2D& right);
    void operator-=(Vector2D& right);

    Vector2D operator*(float scalar) const;
    friend Vector2D operator*(float scalar, Vector2D vect);
    void operator*=(float scalar);
};


#endif //AP_PROJECT_2021_2022_VECTOR2D_H
