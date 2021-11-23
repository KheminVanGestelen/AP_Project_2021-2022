//
// Created by Khemin on 18-11-2021.
//

#include "Game.h"

Game::Game() : mainWindow(sf::VideoMode(640, 480), "JUMP!"), player(){
    player.setRadius(40.f);
    player.setPosition(100.f, 100.f);
    player.setFillColor(sf::Color::Red);
}

void Game::processEvents() {
    sf::Event event{};
    while (mainWindow.pollEvent(event)) {
        if(event.type == sf::Event::Closed)
            mainWindow.close();
    }
}

void Game::update() {

}

void Game::render() {
    mainWindow.clear();
    mainWindow.draw(player);
    mainWindow.display();
}

void Game::run() {
    while (mainWindow.isOpen()) {
        processEvents();
        update();
        render();
    }
}
