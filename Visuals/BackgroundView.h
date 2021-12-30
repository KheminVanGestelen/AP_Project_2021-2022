//
// Created by Khemin on 7-12-2021.
//

#ifndef AP_PROJECT_2021_2022_BACKGROUNDVIEW_H
#define AP_PROJECT_2021_2022_BACKGROUNDVIEW_H

#include "EntityView.h"

/// Class that models the visual representation of a Background element.
class BackgroundView : public EntityView {
public:
    BackgroundView();
    explicit BackgroundView(const sf::Texture& texture);
    BackgroundView(const sf::Texture& texture, const sf::IntRect& rect);
};


#endif //AP_PROJECT_2021_2022_BACKGROUNDVIEW_H
