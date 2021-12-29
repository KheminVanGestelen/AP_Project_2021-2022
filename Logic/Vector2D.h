//
// Created by Khemin on 24-11-2021.
//

#ifndef AP_PROJECT_2021_2022_VECTOR2D_H
#define AP_PROJECT_2021_2022_VECTOR2D_H

#include <utility>

/// Class that represents a 2D vector.
/// \param x : horizontal component of the 2D vector.
/// \param y : vertical component of the 2D vector.
class Vector2D {
    float x;
    float y;
public:
    Vector2D(float x, float y);

    float X() const;
    float Y() const;

    /// Returns the elementwise sum of this and given Vector2D right.
    /// \param right : Vector2D : the Vector2D that is added to this.
    /// \return Vector2D : this + right.
    Vector2D operator+(Vector2D& right) const;

    /// Returns the elementwise difference of this and given Vector2D right.
    /// \param right : Vector2D : the Vector2D that is deducted from this.
    /// \return Vector2D : this - right.
    Vector2D operator-(Vector2D& right) const;

    /// Adds given pair of floats elementwise to this 2D vector.
    /// \param right : pair<float, float> : pair of floats that is added to this.
    void operator+=(std::pair<float, float> right);

    /// Deducts given pair of floats elementwise from this 2D vector.
    /// \param right : pair<float, float> : pair of floats that is deducted from this.
    void operator-=(std::pair<float, float> right);

    /// Adds given Vector2D elementwise to this 2D vector.
    /// \param right : Vector2D : the 2D vector that is added to this.
    void operator+=(Vector2D& right);

    /// Deducts given Vector2D elementwise from this 2D vector.
    /// \param right : Vector2D : the 2D vector that is deducted from this.
    void operator-=(Vector2D& right);

    /// Returns the scalar multiplication of this 2D vector by the given scalar.
    /// \param scalar : float : scalar to multiply this by.
    /// \return Vector2D : this * scalar.
    Vector2D operator*(float scalar) const;

    /// Returns the scalar multiplication of the given 2D vector by the given scalar.
    /// \param scalar : float : scalar to multiply the given 2d vector by.
    /// \param vect : Vector2D : the 2D vector to multiply by the given scalar.
    /// \return Vector2D : scalar * vect.
    friend Vector2D operator*(float scalar, Vector2D vect);

    /// Multiplies this 2D vector by the given scalar.
    /// \param scalar : float : scalar to multiply this by.
    void operator*=(float scalar);
};


#endif //AP_PROJECT_2021_2022_VECTOR2D_H
