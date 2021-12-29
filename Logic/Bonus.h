//
// Created by Khemin on 18-11-2021.
//

#ifndef AP_PROJECT_2021_2022_BONUS_H
#define AP_PROJECT_2021_2022_BONUS_H

#include "Entity.h"
#include "../Visuals/BonusView.h"

/// Class that models a Bonus.
/// \param type : string : indicates the type of the Bonus.
/// \param view : BonusView : the visual representation of the Bonus element.
class Bonus : public Entity {
    std::string type;
public:
    BonusView view;

    Bonus();
    Bonus(float x, float y, float w, float h, BonusView bView, std::string  bType);

    /// Returns a string that indicates the type of the Bonus.
    /// \return string : type of the Bonus
    std::string getType();

    /// Updates the Bonus. The Bonus is moved over the given 2D vector. If the Bonus is a JumpPad its view is also updated.
    /// \param m : Vector2D : the vector over which the Bonus is moved.
    void update(Vector2D m);
};


#endif //AP_PROJECT_2021_2022_BONUS_H
