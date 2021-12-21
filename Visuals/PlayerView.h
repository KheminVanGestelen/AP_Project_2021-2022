//
// Created by Khemin on 25-11-2021.
//

#ifndef AP_PROJECT_2021_2022_PLAYERVIEW_H
#define AP_PROJECT_2021_2022_PLAYERVIEW_H

#include "EntityView.h"

class PlayerView : public EntityView {
public:
    sf::Sprite rocket;

    PlayerView();
    explicit PlayerView(const sf::Texture& texture, const sf::Texture &rocketTexture);
    PlayerView(const sf::Texture& texture, const sf::Texture &rocketTexture,
               const sf::IntRect& rect, const sf::IntRect& rect2);

    void update(float ySpeed, bool movingLeft, bool movingRight);
    void setSpritePos(std::pair<float, float> newPos) override;

};


#endif //AP_PROJECT_2021_2022_PLAYERVIEW_H
