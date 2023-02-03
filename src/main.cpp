#include <iostream>
#include "include/game.hpp"

using namespace std;

int main()
{
    Game game;
    game.run();
    return 0;
}
// g++ src/main.cpp src/game.cpp src/map.cpp src/player.cpp -I//opt/homebrew/Cellar/sfml/2.5.1_2/Include -o app -L/opt/homebrew/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system