#include "Visuals/Game.h"

std::shared_ptr<Stopwatch> Stopwatch::instance = nullptr;
std::shared_ptr<Random> Random::instance  = nullptr;
std::shared_ptr<TextureLoader> TextureLoader::instance  = nullptr;

int main(int argc, char* argv[]){
    int highestScore = 0;
    std::fstream file("../Assets/HighScore.txt", std::ios_base::in);
    file >> highestScore;

    Game game(highestScore);
    game.run();

    return 0;
}
