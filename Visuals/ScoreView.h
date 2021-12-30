//
// Created by Khemin on 26-12-2021.
//

#ifndef AP_PROJECT_2021_2022_SCOREVIEW_H
#define AP_PROJECT_2021_2022_SCOREVIEW_H


#include <iostream>
#include "SFML/Graphics.hpp"

/// Class that models the visual representation of the Score
/// \param scoreFont : sf::Font : font used by the scoreText to display the Score
/// \param scoreText : sf::Text : SFML Text class that contains a string displaying the Score
class ScoreView {
    sf::Font scoreFont;
public:
    sf::Text scoreText;

    ScoreView();

    /// Updates the string of scoreText to the given string s.
    /// \param s : string : new string to set
    void updateString(const std::string& s);
};


#endif //AP_PROJECT_2021_2022_SCOREVIEW_H
