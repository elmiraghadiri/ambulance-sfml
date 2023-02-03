#include "../include/player.hpp"
#include <iostream>

using namespace std;
using namespace sf;

Player::Player()
{
    initVariables();
}

void Player::initVariables()
{
    if (!ambulance.loadFromFile("./photos/ambulance50.png"))
    {
        cout << "can not open ambulance file" << endl;
    }
    ambulance.setSmooth(true);
    player.setTexture(ambulance);
    player.setOrigin(Vector2f(50, 50));
    player.setPosition(Vector2f(18 * 50 + 10, 16 * 50));
    direction = 'w';
}

void Player::move(char dir)
{
    if (dir != direction)
    {
        switch (direction)
        {
        case 'a':
            player.rotate(90);
            break;
        case 'd':
            player.rotate(-90);
            break;
        case 's':
            player.rotate(-180);
            break;
        
        default:
            break;
        }
        switch (dir)
        {
        case 'a':
            direction = 'a';
            player.rotate(-90);
            break;
        case 'w':
            direction = 'w';
            break;
        case 'd':
            direction = 'd';
            player.rotate(90);
            break;
        case 's':
            player.rotate(180);
            direction = 's';
            break;
        default:
            break;
        }
    }
    
    switch (dir)
    {
    case 'a':
        player.move(-10, 0);    
        break;
    case 'w':
        player.move(0, -10);    
        break;
    case 'd':
        player.move(10, 0);    
        break;
    case 's':
        player.move(0, 10);    
        break;
    default:
        break;
    }
    
}

void Player::showPlayer(RenderWindow &window)
{
    window.draw(player);
}