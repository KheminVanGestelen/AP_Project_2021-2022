//
// Created by Khemin on 18-11-2021.
//

#ifndef AP_PROJECT_2021_2022_GAME_H
#define AP_PROJECT_2021_2022_GAME_H

#include <SFML/Graphics.hpp>
#include "../Logic/Stopwatch.h"


class Game {
    sf::RenderWindow mainWindow;
    //time in ms per frame
    long long int timePerFrame;
    sf::CircleShape player;
    bool pIsMovingLeft = false;
    bool pIsMovingRight = false;

public:
    Game();
    void run();
private:
    void handlePlayerInput(sf::Keyboard::Key key, bool pressed);
    void processEvents();
    void update();
    void render();
};


#endif //AP_PROJECT_2021_2022_GAME_H
