//
// Created by Khemin on 25-11-2021.
//

#ifndef AP_PROJECT_2021_2022_PLAYERVIEW_H
#define AP_PROJECT_2021_2022_PLAYERVIEW_H

#include "EntityView.h"

class PlayerView : public EntityView {
public:
    PlayerView();
    explicit PlayerView(const sf::Texture& texture);
    PlayerView(const sf::Texture& texture, const sf::IntRect& rect);

    void update(float ySpeed, bool movingLeft, bool movingRight);

};


#endif //AP_PROJECT_2021_2022_PLAYERVIEW_H
