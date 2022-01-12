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
#include "Score.h"

/// Class that models the game World.
/// \param gravity : float : factor that determines gravity in the world
/// \param difficulty : float : factor that determines difficulty of the game
/// \param diffBreakpoint : float : height in the world at which difficulty increases
/// \param lastJumpLoc : pair<int, int> : location (x,y) to determine if player jumps on same platform multiple times
/// \param factory : shared_ptr<AbstractFactory> : Factory class to create Entities
/// \param rng : shared_ptr<Random> : Random class singleton instance to generate (pseudo-)random numbers
/// \param player : Player : Player character
/// \param platforms : vector<Platform> : container with all platforms present in the world
/// \param bgElements : vector<Background> : container with all the Background elements
/// \param score : Score : Score of the game
/// \param camera : Camera : Main Camera in the world
class World {
    float gravity;
    float difficulty;
    float diffBreakpoint;
    std::pair<int, int> lastJumpLoc;

    std::shared_ptr<AbstractFactory> factory;
    std::shared_ptr<Random> rng;
public:
    Player player;
    std::vector<Platform> platforms;
    std::vector<Background> bgElements;
    Score score;
    Camera camera;

    World(std::shared_ptr<AbstractFactory> fact, Camera cam, int highestScore = 0);

    float getGravity() const;
    float getDifficulty() const;
    float getDiffBreakpoint() const;
    Score getScore() const;

    /// Generates a random new platform above the highest platform in the world and within a range determined by the difficulty.
    /// \return Platform : Generated platform
    Platform generateRandomPlatform();

    /// Initializes a Player character in the world.
    void initializePlayer();

    /// Initializes 30 platforms in the world to fill the first camera view.
    void initializePlatforms();

    /// Initializes the Background.
    void initializeBackground();

    /// Checks if the Player collides with a Platform or a usable Bonus. Makes the Player act accordingly.
    void checkCollisions();

    /// Changes the world gravity between 2 values. 0.5 if the player is in a Rocket, 0.1 otherwise.
    /// \param playerInRocket : bool : true if player is in a Rocket, false otherwise
    void updateGravity(bool playerInRocket);

    /// Updates the World.
    void update();

    /// Resets the World to start a new game.
    void reset();
};


#endif //AP_PROJECT_2021_2022_WORLD_H
