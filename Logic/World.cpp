//
// Created by Khemin on 18-11-2021.
//

#include "World.h"

World::World(std::shared_ptr<AbstractFactory> fact, Camera cam) : factory(std::move(fact)), camera(cam), score(Score()){
    difficulty = 0.1;
    diffBreakpoint = 2500.0;
    lastJumpLoc = {0,0};

    player = Player();
    platforms = std::vector<Platform>();
    bgElements = std::vector<Background>();
    gravity = 0.1;

    rng = Random::getInstance();
}

float World::getGravity() const {
    return gravity;
}

float World::getDifficulty() const {
    return difficulty;
}

float World::getDiffBreakpoint() const {
    return diffBreakpoint;
}

Score World::getScore() const {
    return score;
}

Platform World::generateRandomPlatform() {
    float minY;
    if (platforms.empty()){
        minY = 0.0;
    }
    else {
        minY = platforms.back().Y() + platforms.back().getHeight() + 1;
        if (platforms.back().hasUsableBonus())
            minY += platforms.back().bonus.getHeight();
    }
    float maxY = minY + (difficulty * ((camera.height()/2) - 50));

    float minX = -camera.width()/2 + 24;
    float maxX = camera.width()/2 - 24;

    float randX = rng->randFloat(minX, maxX);
    float randY = rng->randFloat(minY, maxY);

    int r1 = Random::getInstance()->randInt(0, 100);
    std::pair<bool, Bonus> bonusPair;
    if (r1 < 15 && camera.centerHeight() > 1000) {
        bonusPair = std::pair<bool, Bonus>(true, factory->createBonus(randX, randY + 16));
    } else {
        bonusPair = std::pair<bool, Bonus>(false, Bonus());
    }

    return factory->createPlatform(randX, randY, camera.centerHeight(), bonusPair);
}

void World::initializePlayer() {
    player = factory->createPlayer();
}

void World::initializePlatforms() {
    for (unsigned int i = 0; i < 30; i++){
        platforms.push_back(generateRandomPlatform());
    }
}

void World::initializeBackground() {
    bgElements.push_back(factory->createBackground(0.0,"Background"));
    bgElements.push_back(factory->createBackground(1024.0, "Background"));
    bgElements.push_back(factory->createBackground(0.0,"StarsFar"));
    bgElements.push_back(factory->createBackground(1024.0, "StarsFar"));
    bgElements.push_back(factory->createBackground(0.0,"StarsClose"));
    bgElements.push_back(factory->createBackground(1024.0, "StarsClose"));
}

void World::checkCollisions() {
    if (player.Y() <= 0.0)
        player.jump();
    for (Platform& pl : platforms){
        float plMovement = 0.0;
        if (pl.isMovingVertical() && pl.getYSpeed() > 0.0){
            plMovement = pl.getYSpeed();
        }
        // Condition to check if player can touch the top of the platform (width)
        if ((player.X() - (player.getWidth()/4) >= pl.X() - (pl.getWidth()/2) && player.X() - (player.getWidth()/4) <= pl.X() + (pl.getWidth()/2))
            || (player.X() + (player.getWidth()/4) >= pl.X() - (pl.getWidth()/2) && player.X() + (player.getWidth()/4) <= pl.X() + (pl.getWidth()/2))
            || (player.X() >= pl.X() - (pl.getWidth()/2) && player.X() <= pl.X() + (pl.getWidth()/2))){
            // Condition checks if the player is above the platform and will go through the platform in the next frame.
            // (Collision occurs)
            if(player.Y() > pl.Y()+pl.getHeight() && player.Y() + player.getYSpeed() <= pl.Y()+pl.getHeight()+plMovement && pl.isVisible()){
                if (pl.isFragile()){
                    pl.setVisible(false);
                }
                if (pl.hasUsableBonus()) {
                    pl.setUsableBonus(false);
                    if (pl.bonus.getType() == "Rocket")
                        player.enterRocket();
                    if (pl.bonus.getType() == "JumpPad")
                        player.bounce();
                } else {
                    player.jump();
                }
                if ((lastJumpLoc.first == std::floor(pl.X()) && lastJumpLoc.second == std::floor(pl.Y())) ||
                    (lastJumpLoc.first == std::floor(pl.X()) && pl.isMovingVertical()) ||
                    (lastJumpLoc.second == std::floor(pl.Y()) && pl.isMovingHorizontal()))
                {
                    score.decrease(500);
                } else {
                    lastJumpLoc = {std::floor(pl.X()), std::floor(pl.Y())};
                }
            }
        }
    }
}

void World::updateGravity(bool playerInRocket) {
    if (playerInRocket)
        gravity = 0.5;
    else
        gravity = 0.1;
}

void World::update() {
    checkCollisions();

    if (player.X() < (-camera.width() / 2)) {
        player.move(Vector2D(camera.width(), 0));
    }
    if (player.X() > (camera.width() / 2)) {
        player.move(Vector2D(-camera.width(), 0));
    }

    player.update(gravity);
    updateGravity(player.isUsingRocket());

    for (Platform &pl : platforms) {
        pl.update(camera.width());
    }

    for (Background& bgEl : bgElements) {
        bgEl.update(camera.speed(), camera.bottomHeight());
    }

    if (!platforms.front().isMovingVertical() &&
        platforms.front().Y() + platforms.front().getHeight() < camera.bottomHeight() - 48) {
        platforms.erase(platforms.begin());
        platforms.push_back(generateRandomPlatform());
    }

    if (platforms.front().getVerticalRange().second &&
        platforms.front().getVerticalRange().first.second + platforms.front().getHeight() < camera.bottomHeight() - 48) {
        platforms.erase(platforms.begin());
        platforms.push_back(generateRandomPlatform());
    }

    if (camera.speed() > 0.0) {
        score.increase(std::floor(camera.speed()/5));
    }

    camera.update(player.Y(), player.getYSpeed());
    if (difficulty < 1.0 && camera.centerHeight() > diffBreakpoint) {
        diffBreakpoint += 2500.0;
        if (difficulty <= 0.95)
            difficulty += 0.05;
        else
            difficulty = 1.0;
    }
}

void World::reset() {
    platforms.clear();
    bgElements.clear();

    camera.reset();
    score.reset();
    difficulty = 0.1;
    diffBreakpoint = 2500.0;
    lastJumpLoc = {0,0};
    gravity = 0.1;

    initializePlayer();
    initializePlatforms();
    initializeBackground();
}
