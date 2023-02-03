#pragma once
#include <fstream>
#include <iostream>
#include "player.hpp"
#include "map.hpp"

class Game
{
private:
    Map map;
    Player player;
    sf::Font font;
    sf::Text moveCount;
    sf::Text Count;
    int moveNumber;
    std::string name;
    std::fstream file;
    void save();
    void winScreen(sf::RenderWindow & window);
public:
    void run();
    Game();
};
