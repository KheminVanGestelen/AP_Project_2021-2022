//
// Created by Khemin on 18-11-2021.
//

#ifndef AP_PROJECT_2021_2022_WORLD_H
#define AP_PROJECT_2021_2022_WORLD_H

#include <vector>
#include <memory>
#include "Player.h"
#include "Platform.h"
#include "Background.h"
#include "AbstractFactory.h"
#include "Random.h"
#include "Camera.h"

class World {
    float gravity;
    float difficulty;
    float diffBreakpoint;

    std::shared_ptr<AbstractFactory> factory;
    std::shared_ptr<Random> rng;

public:
    Player player;
    std::vector<Platform> platforms;
    std::vector<Background> bgElements;
    Camera camera;

    World();
    World(std::shared_ptr<AbstractFactory> fact, Camera cam);

    float getGravity() const;
    float getDifficulty() const;
    float getDiffBreakpoint() const;

    Platform generateRandomPlatform();

    void initializePlayer();
    void initializePlatforms();
    void initializeBackground();
    void checkCollisions();
    void updateGravity(bool playerInRocket);
    void update();
};


#endif //AP_PROJECT_2021_2022_WORLD_H
