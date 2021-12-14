//
// Created by Khemin on 18-11-2021.
//

#include "World.h"

World::World() : factory(nullptr), player(Player()), camera(Camera()){
    difficulty = 0.1;
    diffBreakpoint = 5000.0;
    platforms = std::vector<Platform>();
    bonuses = std::vector<Bonus>();
    gravity = 0.0;

    rng = Random::getInstance();
}

World::World(std::shared_ptr<AbstractFactory> fact, Camera cam) : factory(std::move(fact)), camera(cam){
    difficulty = 0.1;
    diffBreakpoint = 5000.0;
    platforms = std::vector<Platform>();
    bonuses = std::vector<Bonus>();
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

Platform World::generateRandomPlatform() {
    float minY;
    if (platforms.empty()){
        minY = 0.0;
    }
    else {
        minY = platforms.back().Y() + platforms.back().getHeight() + 1;
    }
    float maxY = minY + (difficulty * (camera.height()/2));

    float minX = -camera.width()/2 + 24;
    float maxX = camera.width()/2 - 24;

    float randX = rng->randFloat(minX, maxX);
    float randY = rng->randFloat(minY, maxY);

    return factory->createPlatform(randX, randY, camera.centerHeight());
}

void World::initializePlayer() {
    player = factory->createPlayer();
}

void World::initializePlatforms() {
    for (unsigned int i = 0; i < 30; i++){
        platforms.push_back(generateRandomPlatform());
    }
}

void World::checkCollisions() {
    if (player.Y() <= 0.0)
        player.jump();
    for (Platform& pl : platforms){
        // Condition to check if player is within the platforms width.
        if (player.X() >= pl.X() - (pl.getWidth()/2) && player.X() <= pl.X() + (pl.getWidth()/2)){
            // Condition checks if the player is above the platform and will go through the platform in the next frame.
            // (Collision occurs)
            if(player.Y() > pl.Y()+pl.getHeight() && player.Y() + player.getYSpeed() <= pl.Y()+pl.getHeight() && pl.isVisible()){
                if (pl.isFragile()){
                    pl.setVisible(false);
                }
                player.jump();
            }
        }
    }
}

void World::update() {
    checkCollisions();

    if (player.X() < (-camera.width()/2)){
        player.move(Vector2D(camera.width(), 0));
    }
    if (player.X() > (camera.width()/2)){
        player.move(Vector2D(-camera.width(), 0));
    }

    player.update(gravity);

    for (Platform& pl : platforms){
        pl.update(camera.width());
    }

    if (!platforms.front().isMovingVertical() && platforms.front().Y() + platforms.front().getHeight() < camera.bottomHeight()) {
        platforms.erase(platforms.begin());
        platforms.push_back(generateRandomPlatform());
    }

    if (platforms.front().getVerticalRange().second && platforms.front().getVerticalRange().first.second + platforms.front().getHeight() < camera.bottomHeight()) {
        platforms.erase(platforms.begin());
        platforms.push_back(generateRandomPlatform());
    }

    camera.update(player.Y());
    if (difficulty < 1.0 && camera.centerHeight() > diffBreakpoint){
        diffBreakpoint += 5000.0;
        if (difficulty <= 0.9)
            difficulty += 0.1;
        else
            difficulty = 1.0;
    }
}