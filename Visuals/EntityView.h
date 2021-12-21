//
// Created by Khemin on 25-11-2021.
//

#ifndef AP_PROJECT_2021_2022_ENTITYVIEW_H
#define AP_PROJECT_2021_2022_ENTITYVIEW_H

#include "../Logic/Observer.h"
#include "SFML/Graphics.hpp"

class EntityView : public Observer {
public:
    sf::Sprite sprite;

    EntityView();
    explicit EntityView(const sf::Texture& texture);
    EntityView(const sf::Texture& texture, const sf::IntRect& rect);

    virtual void setSpritePos(std::pair<float, float> newPos);
};


#endif //AP_PROJECT_2021_2022_ENTITYVIEW_H
