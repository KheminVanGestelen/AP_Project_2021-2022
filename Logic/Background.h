//
// Created by Khemin on 18-11-2021.
//

#ifndef AP_PROJECT_2021_2022_BACKGROUND_H
#define AP_PROJECT_2021_2022_BACKGROUND_H


#include "Entity.h"
#include "../Visuals/BackgroundView.h"

/// Class that models a Background element.
/// \param movinBG : bool : true if the Background element can move vertically.
/// \param movementfactor : float : factor that determines how fast the Background element will move.
/// \param ySpeed : float : the vertical movement speed of the Background element.
/// \param view : BackgroundView : the visual representation of the Background element.
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

    /// Updates the background element. Moves the background element if it is out of camera view.
    /// If the Background can move, this function updates the speed according to the speed of the camera (Parallax effect).
    ///
    /// \param camSpeed : float : the vertical movement speed of the camera
    /// \param camBottomHeight : float : the height of the bottom edge of the camera
    void update(float camSpeed, float camBottomHeight);
};


#endif //AP_PROJECT_2021_2022_BACKGROUND_H
