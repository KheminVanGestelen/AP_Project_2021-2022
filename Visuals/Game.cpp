//
// Created by Khemin on 18-11-2021.
//

#include "Game.h"

Game::Game() : mainWindow(sf::VideoMode(640, 480), "JUMP!"), timePerFrame(1000/60), player(){
    player.setRadius(10.f);
    player.setPosition(100.f, 100.f);
    player.setFillColor(sf::Color::Red);
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool pressed) {
    if(key == sf::Keyboard::Q)
        pIsMovingLeft = pressed;
    if(key == sf::Keyboard::D)
        pIsMovingRight = pressed;

}

void Game::processEvents() {
    sf::Event event{};
    while (mainWindow.pollEvent(event)) {
        switch(event.type){
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                mainWindow.close();
                break;
        }
    }
}

void Game::update() {
    sf::Vector2f movement(0.f, 0.f);
    if (pIsMovingLeft)
        movement.x -= 5.f;
    if (pIsMovingRight)
        movement.x += 5.f;

    player.move(movement);
}

void Game::render() {
    mainWindow.clear();
    mainWindow.draw(player);
    mainWindow.display();
}

void Game::run() {
    Stopwatch clock;
    long long int timeSinceUpdate = 0;

    while (mainWindow.isOpen()) {
        processEvents();
        timeSinceUpdate += clock.reset();
        while (timeSinceUpdate > timePerFrame) {
            timeSinceUpdate -= timePerFrame;
            processEvents();
            update();
        }
        render();
    }
}
