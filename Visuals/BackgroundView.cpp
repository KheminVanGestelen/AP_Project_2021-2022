//
// Created by Khemin on 7-12-2021.
//

#include "BackgroundView.h"

BackgroundView::BackgroundView() : EntityView(), sprite2(sf::Sprite()) {}

BackgroundView::BackgroundView(const sf::Texture &texture) : EntityView(texture) , sprite2(sf::Sprite(texture)) {}

BackgroundView::BackgroundView(const sf::Texture &texture, const sf::IntRect &rect) : EntityView(texture, rect) , sprite2(sf::Sprite(texture, rect)) {}
