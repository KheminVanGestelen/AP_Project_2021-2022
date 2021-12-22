//
// Created by Khemin on 18-11-2021.
//

#ifndef AP_PROJECT_2021_2022_BONUS_H
#define AP_PROJECT_2021_2022_BONUS_H

#include "Entity.h"
#include "../Visuals/BonusView.h"

class Bonus : public Entity {
    std::string type;
public:
    BonusView view;

    Bonus();
    Bonus(float x, float y, float w, float h, BonusView bView, std::string  bType);

    std::string getType();
    void update(Vector2D m);
};


#endif //AP_PROJECT_2021_2022_BONUS_H
