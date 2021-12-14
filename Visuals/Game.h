//
// Created by Khemin on 18-11-2021.
//

#ifndef AP_PROJECT_2021_2022_GAME_H
#define AP_PROJECT_2021_2022_GAME_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "../Logic/Stopwatch.h"
#include "ConcreteFactory.h"
#include "../Logic/World.h"
#include "../Logic/Vector2D.h"


using namespace std;

class Game {
    sf::RenderWindow mainWindow;
    //time in ms per frame
    long long int timePerFrame;
    shared_ptr<ConcreteFactory> factory;
    World world;
public:
    Game();
    void run();
private:
    void handlePlayerInput(sf::Keyboard::Key key, bool pressed);
    void processEvents();
    void updateSpriteCoord();
    void update();
    void render();
};


#endif //AP_PROJECT_2021_2022_GAME_H
