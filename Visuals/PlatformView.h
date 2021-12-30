//
// Created by Khemin on 25-11-2021.
//

#ifndef AP_PROJECT_2021_2022_PLATFORMVIEW_H
#define AP_PROJECT_2021_2022_PLATFORMVIEW_H

#include "EntityView.h"

/// Class that models the visual representation of a Platform.
class PlatformView : public EntityView {
public:
    PlatformView();
    explicit PlatformView(const sf::Texture& texture);
    PlatformView(const sf::Texture& texture, const sf::IntRect& rect);

    /// Updates the texture of the PlatformView
    /// \param fragile : bool : true if the Platform is a fragile platform, false otherwise.
    /// \param movingHorizontal : bool : true if the Platform moves horizontally, false otherwise.
    /// \param movingVertical : bool : true if the Platform moves vertically, false otherwise.
    void update(bool fragile, bool movingHorizontal, bool movingVertical);
};


#endif //AP_PROJECT_2021_2022_PLATFORMVIEW_H
