#include "Visuals/Game.h"

std::shared_ptr<Stopwatch> Stopwatch::instance = nullptr;
std::shared_ptr<Random> Random::instance  = nullptr;
std::shared_ptr<TextureLoader> TextureLoader::instance  = nullptr;

int main(int argc, char* argv[]){
    Game game;
    game.run();

    return 0;
}
