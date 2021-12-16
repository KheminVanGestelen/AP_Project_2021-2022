//
// Created by Khemin on 18-11-2021.
//

#ifndef AP_PROJECT_2021_2022_BACKGROUND_H
#define AP_PROJECT_2021_2022_BACKGROUND_H


#include "Entity.h"
#include "../Visuals/BackgroundView.h"

class Background : public Entity {
    bool movingBG;
    float movementfactor;
    float ySpeed;
public:
    BackgroundView view;

    Background();
    Background(float x, float y, float w, float h, BackgroundView bgView, float mfact);

    float getYSpeed() const;
    void setYSpeed(float s);

    void update(float camSpeed, float camBottomHeight);
};


#endif //AP_PROJECT_2021_2022_BACKGROUND_H
