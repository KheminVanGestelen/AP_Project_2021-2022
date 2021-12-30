//
// Created by Khemin on 18-11-2021.
//

#include "Game.h"

Game::Game() : mainWindow(sf::VideoMode(750, 750) , "Is working?"), factory(std::make_shared<ConcreteFactory>(ConcreteFactory())),
               world(World(factory, Camera((float) mainWindow.getSize().x,(float) mainWindow.getSize().y))) {
    textures = TextureLoader::getInstance()->textures();
    world.initializePlayer();
    world.initializePlatforms();
    world.initializeBackground();
    timePerFrame = 1000/60;
    gameOver = false;
    gameOverScreen = sf::Sprite(textures["GameOver"]);
    gameOverScreen.setScale(2.0,2.0);
    gameOverScreen.setPosition((float) (mainWindow.getSize().x-512)/2, (float) (mainWindow.getSize().y-512)/2);
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool pressed) {
    if(key == sf::Keyboard::Q) {
        world.player.setMovingLeft(pressed);
    }
    if(key == sf::Keyboard::D) {
        world.player.setMovingRight(pressed);
    }
    if(key == sf::Keyboard::R && !pressed && gameOver) {
        reset();
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
        if (pl.hasUsableBonus()) {
            pl.bonus.view.setSpritePos(world.camera.getWindowCoord(pl.bonus));
        }
    }
    for (Background& bgEl : world.bgElements) {
        bgEl.view.setSpritePos(world.camera.getWindowCoord(bgEl));
    }
}


void Game::update() {
    world.update();
    if (world.player.Y() < world.camera.bottomHeight() - 50) {
        gameOver = true;
    }
}

void Game::render() {
    if (gameOver) {
        mainWindow.clear();
        mainWindow.draw(gameOverScreen);
        mainWindow.display();
    }
    else {
        updateSpriteCoord();
        world.score.view.updateString(world.score.getScoreString());

        mainWindow.clear();
        for (const Background &bgEl: world.bgElements) {
            mainWindow.draw(bgEl.view.sprite);
        }

        for (const Platform &pl: world.platforms) {
            if (pl.isVisible()) {
                mainWindow.draw(pl.view.sprite);
                if (pl.hasUsableBonus())
                    mainWindow.draw(pl.bonus.view.sprite);
            }
        }

        mainWindow.draw(world.score.view.scoreText);

        if (world.player.isUsingRocket()) {
            mainWindow.draw(world.player.view.rocket);
        } else {
            mainWindow.draw(world.player.view.sprite);
        }

        mainWindow.display();
    }
}

void Game::run() {
    std::shared_ptr<Stopwatch> clock = Stopwatch::getInstance();
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

void Game::reset() {
    world.reset();
    gameOver = false;
}
