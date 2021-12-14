//
// Created by Khemin on 25-11-2021.
//

#include "EntityView.h"

EntityView::EntityView() : sprite(sf::Sprite()) {}

EntityView::EntityView(const sf::Texture &texture) : sprite(sf::Sprite(texture)){}

EntityView::EntityView(const sf::Texture &texture, const sf::IntRect &rect) : sprite(sf::Sprite(texture, rect)) {}

void EntityView::setSpritePos(std::pair<float, float> newPos) {
    sprite.setPosition(newPos.first, newPos.second);
}
