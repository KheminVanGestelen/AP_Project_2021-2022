//
// Created by Khemin on 26-11-2021.
//

#include "Score.h"

Score::Score() : view(ScoreView()), score(0){}

void Score::increase(int i) {
    score += i;
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
