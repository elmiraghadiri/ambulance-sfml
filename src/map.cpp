#include "../include/map.hpp"
#include <iostream>

using namespace std;
using namespace sf;

Map::Map()
{
    initMap();
    convertSketch();
}

void Map::initMap()
{
    array<string, 21> sketch1 = {
        "#####################",
        "#H    ####          #",
        "#      ###          #",
        "#       ##          #",
        "#        #          #",
        "#                   #",
        "#          ##########",
        "#          #        #",
        "#      #####        #",
        "#      #####        #",
        "#      #####        #",
        "#                   #",
        "#                   #",
        "#                   #",
        "#######             #",
        "#             #     #",
        "#             #     #",
        "#             #     #",
        "#             #     #",
        "#####################",
        "                     ",
    };
    sketch = sketch1;
}

void Map::convertSketch()
{
    if (!wallTexture.loadFromFile("./photos/wall50.png"))
    {
        cout << "can not open wall photo" << endl;
    }
    wallTexture.setSmooth(true);
    if (!hospital.loadFromFile("./photos/hospital50.png"))
    {
        cout << "can not open hospital photo" << endl;
    }
    hospital.setSmooth(true);

    if (!background.loadFromFile("./photos/back.png"))
    {
        cout << "can not open background photo" << endl;
    }
    background.setSmooth(true);
    backSprite.setTexture(background);
    
    for (size_t i = 0; i < 20       ; i++)
    {
        for (size_t j = 0; j < 23; j++)
        {
            switch (sketch[i][j])
            {
                case 'H':
                    Hsprite.setTexture(hospital);
                    Hsprite.setPosition(Vector2f(j * 50, i * 50));
                    // walls.push_back(Hsprite);
                    break;
            case '#':
                sprite.setTexture(wallTexture);
                sprite.setPosition(Vector2f(j * 50, i * 50));
                walls.push_back(sprite);
                break;
            default:
                break;
            }
        }
    }
    
}

void Map::showMap(RenderWindow &window)
{
    window.draw(backSprite);
    for (auto i : walls)
    {
        window.draw(i);
    }
    window.draw(Hsprite);
}

int Map::update(int move, int &score)
{
    system("clear");
    
    int x, y;
    bool find = false;
    for (size_t i = 0; i < sketch.size(); i++)
    {
        for (size_t j = 0; j < sketch[0].size(); j++)
        {
            if (sketch[i][j] == 'P')
            {
                x = j;
                y = i;
                find = true;
                break;
            }
        }
        if (find)
        {
            break;
        }        
    }
    int oldX = x, oldY = y;

    if (y == 1 && x == 2 && move == 2)
    {
        if (score == 14)
        {
            cout << "************** YOU Won **************" << endl;    
        } else
        {
            cout << "************** YOU Lost **************" << endl;
            cout << "Points required : 14" << endl;
        }
        cout << "Your score : " << score << endl;
        cout << "Enter 1 to continue..." << endl;
        int n;
        cin >> n;
        if (n == 1)
        {
            //try again
            sketch[13][26] = 'P';
            sketch[1][2] = ' ';
            return -1;
        } else
        {
            return -2;
        }
        
    }
    
    switch (move)
    {
    case 1:
        if (x - 4 > 0)
        {
            x -= 4;
        }
        break;
    case 2:
        if (y - 2 > 0)
        {
            y -= 2;
        }
        
        break;
    case 3:
        if (x + 4 < sketch[0].size())
        {
            x += 4;
        }
        
        break;
    case 4:
        if (y + 2 < 15)
        {
            y += 2;
        }
        
        break;
    default:
        break;
    }
    if (sketch[y][x] != '#')
    {
        sketch[oldY][oldX] = ' ';
        score++;
        sketch[y][x] = 'P';
    }
    return 10;
}

int Map::checkCollision(char dir, Sprite player)
{    
    switch (dir)
    {
    case 'a':
        player.setPosition(Vector2f(player.getPosition().x - 10, player.getPosition().y));
        for(auto i : walls)
        {
            if (i.getGlobalBounds().intersects(player.getGlobalBounds()))
            {
                return 0;
            }
        }
        break;
    case 'w':
        player.setPosition(Vector2f(player.getPosition().x, player.getPosition().y - 10));
        for(auto i : walls)
        {
            if (i.getGlobalBounds().intersects(player.getGlobalBounds()))
            {
                return 0;
            }
        }
        break;
    case 'd':
        player.setPosition(Vector2f(player.getPosition().x + 10, player.getPosition().y));
        for(auto i : walls)
        {
            if (i.getGlobalBounds().intersects(player.getGlobalBounds()))
            {
                return 0;
            }
        }
        break;
    case 's':
        player.setPosition(Vector2f(player.getPosition().x, player.getPosition().y + 10));
        for(auto i : walls)
        {
            if (i.getGlobalBounds().intersects(player.getGlobalBounds()))
            {
                return 0;
            }
        }
        break;
    
    default:
        break;
    }

    return 1;
}

bool Map::checkWin(Sprite player)
{
    if (player.getGlobalBounds().intersects(Hsprite.getGlobalBounds()))
    {
        return true;
    }
    return false;
}