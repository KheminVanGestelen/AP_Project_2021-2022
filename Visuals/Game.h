//
// Created by Khemin on 18-11-2021.
//

#ifndef AP_PROJECT_2021_2022_GAME_H
#define AP_PROJECT_2021_2022_GAME_H

#include <SFML/Graphics.hpp>


class Game {
    sf::RenderWindow mainWindow;
    sf::CircleShape player;
public:
    Game();
    void run();
private:
    void processEvents();
    void update();
    void render();
};


#endif //AP_PROJECT_2021_2022_GAME_H
