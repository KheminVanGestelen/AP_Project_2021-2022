//
// Created by Khemin on 25-11-2021.
//

#include "BonusView.h"

BonusView::BonusView() : EntityView() {}

BonusView::BonusView(const sf::Texture &texture) : EntityView(texture) {}

BonusView::BonusView(const sf::Texture &texture, const sf::IntRect &rect) : EntityView(texture, rect) {}
