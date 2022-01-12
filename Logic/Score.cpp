//
// Created by Khemin on 26-11-2021.
//

#include "Score.h"

Score::Score() : view(ScoreView()), score(0), highScore(0){}

Score::Score(int highestScore) : view(ScoreView()), score(0), highScore(highestScore){}

int Score::getHighScore() const {
    return highScore;
}

void Score::increase(int i) {
    score += i;
    if (score > highScore)
        highScore = score;
}

void Score::decrease(int i) {
    if (score < i)
        score = 0;
    else
        score -= i;
}

std::string Score::getScoreString() const {
    return "Score: " + std::to_string(score);
}

std::string Score::getHighScoreString() const {
    return "Highest Score: " + std::to_string(highScore);
}

void Score::reset() {
    score = 0;
}
