//
// Created by Khemin on 25-11-2021.
//

#ifndef AP_PROJECT_2021_2022_BONUSVIEW_H
#define AP_PROJECT_2021_2022_BONUSVIEW_H

#include "EntityView.h"

class BonusView : public EntityView {
public:
    BonusView();
    explicit BonusView(const sf::Texture& texture);
    BonusView(const sf::Texture& texture, const sf::IntRect& rect);

};


#endif //AP_PROJECT_2021_2022_BONUSVIEW_H
