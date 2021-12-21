//
// Created by Khemin on 25-11-2021.
//

#include "PlayerView.h"

PlayerView::PlayerView() : EntityView(), rocket(sf::Sprite()) {}

PlayerView::PlayerView(const sf::Texture &texture, const sf::Texture &rocketTexture) : EntityView(texture), rocket(sf::Sprite(rocketTexture)) {}

PlayerView::PlayerView(const sf::Texture &texture, const sf::Texture &rocketTexture,
                       const sf::IntRect &rect, const sf::IntRect &rect2) : EntityView(texture, rect), rocket(sf::Sprite(rocketTexture)) {}

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

    sf::IntRect prevBox = rocket.getTextureRect();
    if (prevBox.left == 32)
        rocket.setTextureRect(sf::IntRect(0,0,32,48));
    if (prevBox.left == 0)
        rocket.setTextureRect(sf::IntRect(32,0,32,48));
}

void PlayerView::setSpritePos(std::pair<float, float> newPos) {
    sprite.setPosition(newPos.first, newPos.second);
    rocket.setPosition(newPos.first, newPos.second);
}
