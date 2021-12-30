//
// Created by Khemin on 25-11-2021.
//

#ifndef AP_PROJECT_2021_2022_BONUSVIEW_H
#define AP_PROJECT_2021_2022_BONUSVIEW_H

#include "EntityView.h"

/// Class that models the visual representation of a Bonus.
/// \param framecounter : int : a counter to slow down the visual updates of the Bonus' frame texture. Only relevant to the JumpPad Bonus.
class BonusView : public EntityView {
    int frameCounter;
public:
    BonusView();
    explicit BonusView(const sf::Texture& texture);
    BonusView(const sf::Texture& texture, const sf::IntRect& rect);

    /// Updates the sprite's visual frame if frameCounter reaches 0.
    void update();

};


#endif //AP_PROJECT_2021_2022_BONUSVIEW_H
