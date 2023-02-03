#pragma once
#include <array>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

class Map
{
private:
    std::array<std::string, 21> sketch;
    std::vector<sf::Sprite> walls;
    sf::Texture background;
    sf::Sprite backSprite;
    void initMap();
    void convertSketch();
    sf::CircleShape player;
    sf::Sprite sprite;
    sf::Sprite Hsprite;
    sf::Texture wallTexture;
    sf::Texture hospital;
public:
    Map();
    void showMap(sf::RenderWindow &window);
    int update(int move, int &score);
    int checkCollision(char dir, sf::Sprite player);
    bool checkWin(sf::Sprite player);
};
