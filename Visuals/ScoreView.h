//
// Created by Khemin on 26-12-2021.
//

#ifndef AP_PROJECT_2021_2022_SCOREVIEW_H
#define AP_PROJECT_2021_2022_SCOREVIEW_H


#include <iostream>
#include "SFML/Graphics.hpp"

class ScoreView {
    sf::Font scoreFont;
public:
    sf::Text scoreText;

    ScoreView();

    void updateString(const std::string& s);
};


#endif //AP_PROJECT_2021_2022_SCOREVIEW_H
