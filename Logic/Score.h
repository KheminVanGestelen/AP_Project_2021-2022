//
// Created by Khemin on 26-11-2021.
//

#ifndef AP_PROJECT_2021_2022_SCORE_H
#define AP_PROJECT_2021_2022_SCORE_H

#include "Observer.h"
#include "../Visuals/ScoreView.h"

/// Class that tracks the Score.
/// \param score : int : the value of the Score
/// \param view : ScoreView : the visual representation of the Score
class Score : public Observer {
    int score;
    int highScore;
public:
    ScoreView view;

    Score();
    explicit Score(int highestScore);

    int getHighScore() const;

    /// Increases the score by given integer i
    /// \param i : integer : the amount of points that is added to the Score.
    void increase(int i);

    /// Decreases the score by given integer i
    /// \param i : integer : the amount of points that is deducted from the Score.
    void decrease(int i);

    /// Returns a string that contains the current score. The string has following form : "Score: [score]"
    std::string getScoreString() const;

    /// Returns a string that contains the highest score. The string has following form : "Highscore: [highScore]"
    std::string getHighScoreString() const;

    /// Resets the Score back to 0.
    void reset();
};


#endif //AP_PROJECT_2021_2022_SCORE_H
