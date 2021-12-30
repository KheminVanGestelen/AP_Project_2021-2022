//
// Created by Khemin on 18-11-2021.
//

#ifndef AP_PROJECT_2021_2022_CAMERA_H
#define AP_PROJECT_2021_2022_CAMERA_H

#include <utility>
#include "Entity.h"
#include <cmath>

/// Class that models the Camera in the world.
/// \param camWidth : float : the width of the camera.
/// \param camHeight : float : the height of the camera.
/// \param camCenter : float : the height in the world at which the center of the camera is located.
/// \param camBottom : float : the height in the world at which the bottom edge of the camera is located.
/// \param camSpeed : float : the vertical movement speed of the camera.
class Camera {
    float camWidth;
    float camHeight;
    float camCenter;
    float camBottom;
    float camSpeed;
public:
    Camera();
    Camera(float w, float h);

    float width() const;
    float height() const;
    float centerHeight() const;
    float bottomHeight() const;
    float speed() const;

    /// Returns the coordinates of the given entity relative to the window's coordinate system
    /// (origin in the top left corner of the window).
    /// \param e : Entity : the entity for which the window coordinates are calculated.
    /// \return : pair<float, float> : the coordinates (x, y) of the entity in the window's coordinate system.
    std::pair<float, float> getWindowCoord(const Entity& e) const;

    /// Updates the camera.
    /// \param playerHeight : float : the world height of the player
    /// \param playerYSpeed : the vertical movement speed of the player
    void update(float playerHeight, float playerYSpeed);

    /// Resets the camera.
    void reset();

};


#endif //AP_PROJECT_2021_2022_CAMERA_H
