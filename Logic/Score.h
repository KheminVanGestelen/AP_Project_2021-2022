//
// Created by Khemin on 26-11-2021.
//

#ifndef AP_PROJECT_2021_2022_SCORE_H
#define AP_PROJECT_2021_2022_SCORE_H

#include "Observer.h"
#include "../Visuals/ScoreView.h"

class Score : public Observer {
    int score;
public:
    ScoreView view;

    Score();

    void increase(int i);
    void decrease(int i);
    std::string getScoreString() const;
};


#endif //AP_PROJECT_2021_2022_SCORE_H
