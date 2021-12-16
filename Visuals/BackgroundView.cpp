//
// Created by Khemin on 7-12-2021.
//

#include "BackgroundView.h"

BackgroundView::BackgroundView() : EntityView() {}

BackgroundView::BackgroundView(const sf::Texture &texture) : EntityView(texture) {}

BackgroundView::BackgroundView(const sf::Texture &texture, const sf::IntRect &rect) : EntityView(texture, rect) {}
