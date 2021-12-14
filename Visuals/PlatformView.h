//
// Created by Khemin on 25-11-2021.
//

#ifndef AP_PROJECT_2021_2022_PLATFORMVIEW_H
#define AP_PROJECT_2021_2022_PLATFORMVIEW_H

#include "EntityView.h"

class PlatformView : public EntityView {
public:
    PlatformView();
    explicit PlatformView(const sf::Texture& texture);
    PlatformView(const sf::Texture& texture, const sf::IntRect& rect);

    void update(bool fragile, bool movingHorizontal, bool movingVertical);
};


#endif //AP_PROJECT_2021_2022_PLATFORMVIEW_H
