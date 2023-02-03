#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{   
private:
    std::string name;
    sf::Texture ambulance;
    sf::Sprite player;
    char direction;
    int score;//number of player move
    int bestScore;//best way
    void initVariables();
public:
    Player();
    sf::Vector2f getPosition() { return player.getPosition(); }
    int getScore() { return score; };
    void move(char dir);
    void showPlayer(sf::RenderWindow &window);
    sf::Sprite getAmbulance() { return player;}

};
