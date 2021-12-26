//
// Created by Khemin on 26-12-2021.
//

#include "ScoreView.h"

ScoreView::ScoreView() {
    if (!scoreFont.loadFromFile("Assets/Sticky_Notes.ttf"))
        std::cerr << "Could not load font from file" << std::endl;
    else {
        scoreText = sf::Text("Score: 0", scoreFont);
        scoreText.setPosition(10.0,10.0);
    }
}

void ScoreView::updateString(const std::string& s) {
    scoreText.setString(s);
}
