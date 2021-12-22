//
// Created by Khemin on 18-11-2021.
//

#include "Bonus.h"

#include <utility>

Bonus::Bonus() : Entity(0.0, 0.0, 1.0, 1.0), view(BonusView()){
    type = "";
}

Bonus::Bonus(float x, float y, float w, float h, BonusView bView, std::string  bType) : Entity(x,y,w,h), view(std::move(bView)), type(std::move(bType)){

}

std::string Bonus::getType() {
    return type;
}

void Bonus::update(Vector2D m) {
    move(m);
    if (type == "JumpPad")
        view.update();
}
