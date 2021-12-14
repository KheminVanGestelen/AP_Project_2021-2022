//
// Created by Khemin on 18-11-2021.
//

#include "Game.h"

Game::Game() : mainWindow(sf::VideoMode(500, 500) , "Is working?"), factory(std::make_shared<ConcreteFactory>(ConcreteFactory())) {
    Camera cam = Camera((float) mainWindow.getSize().x,(float) mainWindow.getSize().y);
    world = World(factory, cam);
    world.initializePlayer();
    world.initializePlatforms();
    timePerFrame = 1000/60;
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool pressed) {
    if(key == sf::Keyboard::Q) {
        world.player.setMovingLeft(pressed);
    }
    if(key == sf::Keyboard::D) {
        world.player.setMovingRight(pressed);
    }
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

void Game::updateSpriteCoord() {
    world.player.view.setSpritePos(world.camera.getWindowCoord(world.player));
    for (Platform& pl : world.platforms){
        pl.view.setSpritePos(world.camera.getWindowCoord(pl));
    }
}


void Game::update() {
    world.update();
}

void Game::render() {
    updateSpriteCoord();

    mainWindow.clear();
    for (const Platform& pl : world.platforms){
        if (pl.isVisible())
            mainWindow.draw(pl.view.sprite);
    }
    mainWindow.draw(world.player.view.sprite);
    mainWindow.display();
}

void Game::run() {
    shared_ptr<Stopwatch> clock = Stopwatch::getInstance();
    long long int timeSinceUpdate = 0;

    while (mainWindow.isOpen()) {
        processEvents();
        timeSinceUpdate += clock->reset();
        while (timeSinceUpdate > timePerFrame) {
            timeSinceUpdate -= timePerFrame;
            processEvents();
            update();
        }
        render();
    }
}
