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
#include "TextureLoader.h"

/// Class that models the Game. Handles input. Contains main game loop. Regulates game speed. Renders to window.
/// \param mainWindow : sf::RenderWindow : SFML RenderWindow class to render all visual elements to.
/// \param timePerFrame : long long int : determines the speed of the game/the frequency of updates. Initialized at 1000 ms/60 frames => 60fps
/// \param gameOver : bool : true if the Player lost (Game Over), false otherwise.
/// \param gameOverScreen : sf::Sprite : the SFML sprite to draw when gameOver is true.
/// \param textures : map<string, sf::Texture> : map with all usable Textures. Obtained from the TextureLoader singleton instance.
/// \param factory : shared_ptr<ConcreteFactory> : pointer to the Concrete implementation of the Factory class. Passed to the World object to be able to create new Entities.
/// \param world : World : the World class object.
class Game {
    sf::RenderWindow mainWindow;
    //time in ms per frame
    long long int timePerFrame;
    bool gameOver;
    sf::Sprite gameOverScreen;

    std::map<std::string, sf::Texture> textures;
    std::shared_ptr<ConcreteFactory> factory;
    World world;
public:
    Game();

    /// Main game loop.
    void run();
private:
    /// Processes player input.
    /// \param key : sf::Keyboard::Key : SFML keycode of the pressed/released key.
    /// \param pressed : bool : true if the key is pressed, false if the key is released.
    /// Note: R resets the game but can only be used if the Player lost -> gameOVer = true.
    void handlePlayerInput(sf::Keyboard::Key key, bool pressed);

    /// Processes events on the input or window. Passes pressed keys to the handlePlayerInput function or closes the window when a sf::Event::Closed event occurs.
    void processEvents();

    /// Updates the positions of all the drawable objects in the World.
    void updateSpriteCoord();

    /// Updates the game. First Updates the World, then checks if the Player lost.
    void update();

    /// Renders all drawable objects to the mainWindow.
    void render();

    /// Resets the Game
    void reset();
};


#endif //AP_PROJECT_2021_2022_GAME_H
