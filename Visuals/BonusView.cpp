//
// Created by Khemin on 25-11-2021.
//

#include "BonusView.h"

BonusView::BonusView() : EntityView(), frameCounter(20) {}

BonusView::BonusView(const sf::Texture &texture) : EntityView(texture), frameCounter(20) {}

BonusView::BonusView(const sf::Texture &texture, const sf::IntRect &rect) : EntityView(texture, rect), frameCounter(20) {}

void BonusView::update() {
    if (frameCounter == 0)
        frameCounter = 20;
    else
        frameCounter -= 1;

    sf::IntRect prevBox = sprite.getTextureRect();
    if (prevBox.left == 64 && frameCounter == 0)
        sprite.setTextureRect(sf::IntRect(0,0,32,32));
    if (prevBox.left != 64 && frameCounter == 0)
        sprite.setTextureRect(sf::IntRect(prevBox.left+32,prevBox.top,prevBox.width,prevBox.height));
}
