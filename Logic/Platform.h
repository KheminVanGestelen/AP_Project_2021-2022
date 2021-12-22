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
    std::pair<std::pair<float, float>, bool> getVerticalRange() const;

    void setUsableBonus(bool b);
    void setVisible(bool b);

    void update(float worldWidth);

};


#endif //AP_PROJECT_2021_2022_PLATFORM_H
