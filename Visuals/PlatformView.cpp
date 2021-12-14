//
// Created by Khemin on 25-11-2021.
//

#include "PlatformView.h"

PlatformView::PlatformView() : EntityView() {}

PlatformView::PlatformView(const sf::Texture &texture) : EntityView(texture) {}

PlatformView::PlatformView(const sf::Texture &texture, const sf::IntRect &rect) : EntityView(texture, rect) {}

void PlatformView::update(bool fragile, bool movingHorizontal, bool movingVertical) {
    if (fragile)
        sprite.setTextureRect(sf::IntRect(0, 0, 48, 12));
    if (movingHorizontal)
        sprite.setTextureRect(sf::IntRect(104, 16, 48, 16));
    if (movingVertical)
        sprite.setTextureRect(sf::IntRect(52, 16, 48, 16));
}
