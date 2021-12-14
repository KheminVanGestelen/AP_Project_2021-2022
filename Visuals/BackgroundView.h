//
// Created by Khemin on 7-12-2021.
//

#ifndef AP_PROJECT_2021_2022_BACKGROUNDVIEW_H
#define AP_PROJECT_2021_2022_BACKGROUNDVIEW_H

#include "EntityView.h"

class BackgroundView : public EntityView {
public:
    sf::Sprite sprite2;

    BackgroundView();
    explicit BackgroundView(const sf::Texture& texture);
    BackgroundView(const sf::Texture& texture, const sf::IntRect& rect);

    //TODO use 2 sprite to display background sprites have size of window/camera
};


#endif //AP_PROJECT_2021_2022_BACKGROUNDVIEW_H
