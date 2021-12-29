//
// Created by Khemin on 18-11-2021.
//

#ifndef AP_PROJECT_2021_2022_PLATFORM_H
#define AP_PROJECT_2021_2022_PLATFORM_H

#include "Entity.h"
#include "Vector2D.h"
#include "../Visuals/PlatformView.h"
#include "Random.h"
#include "Bonus.h"
#include <utility>

/// Class that models a Platform in the world.
/// \param visible : bool : true if the platform is visible, false otherwise.
/// \param usableBonus : bool : true if the platform has a usable Bonus, false otherwise.
/// \param fragile : bool : true if it's a fragile Platform, false otherwise.
/// \param movingHorizontal : bool : true if the platform can move horizontal, false otherwise.
/// \param movingVertical : bool : true if the platform can move vertical, false otherwise.
/// \param horizontalRange : pair<float, float> : the range (minX, maxX) over which a horizontal moving Platform can move.
/// \param verticalRange : pair<float, float> : the range (minY, maxY) over which a vertical moving Platform can move.
/// \param xSpeed : float : the horizontal movement speed of the Platform.
/// \param ySpeed : float : the vertical movement speed of the Platform.
/// \param baseSpeed : float : the base movement speed of the Platform.
/// \param view : PlatformView : the visual respresentation of the Platform.
/// \param bonus : Bonus : the Bonus that is located on the platform.
class Platform : public Entity {
    bool visible;
    bool usableBonus;

    bool fragile;
    bool movingHorizontal;
    bool movingVertical;

    std::pair<float, float> horizontalRange;
    std::pair<float, float> verticalRange;

    float xSpeed;
    float ySpeed;

    float baseSpeed;
public:
    PlatformView view;
    Bonus bonus;

    Platform();
    Platform(float x, float y, float w, float h, PlatformView plView, float heightInWorld, const std::pair<bool, Bonus>& b);

    bool hasUsableBonus() const;
    bool isVisible() const;
    bool isFragile() const;
    bool isMovingHorizontal() const;
    bool isMovingVertical() const;
    float getYSpeed() const;

    /// Returns the vertical movement range of the Platform and a boolean value.
    /// The boolean value indicates if the vertical range is valid to use (true) or not valid (false).
    std::pair<std::pair<float, float>, bool> getVerticalRange() const;

    void setUsableBonus(bool b);
    void setVisible(bool b);

    /// Updates the Platform.
    /// \param worldWidth : float : the width of the world.
    void update(float worldWidth);

};


#endif //AP_PROJECT_2021_2022_PLATFORM_H
