//
// Created by Khemin on 25-11-2021.
//

#include "PlayerView.h"

PlayerView::PlayerView() : EntityView() {}

PlayerView::PlayerView(const sf::Texture &texture) : EntityView(texture) {}

PlayerView::PlayerView(const sf::Texture &texture, const sf::IntRect &rect) : EntityView(texture, rect) {}

void PlayerView::update(float ySpeed, bool movingLeft, bool movingRight) {
    int offset = 0;
    if (movingLeft)
        offset = 96;
    if (movingRight)
        offset = 0;

    if (ySpeed > 1.0)
        sprite.setTextureRect(sf::IntRect(offset, 0, 32, 32));
    if (ySpeed < 0.1 && ySpeed > -0.1)
        sprite.setTextureRect(sf::IntRect(offset + 32, 0, 32, 32));
    if (ySpeed < -1.0)
        sprite.setTextureRect(sf::IntRect(offset + 64, 0, 32, 32));
}
