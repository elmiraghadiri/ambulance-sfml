#include "../include/game.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

Game::Game()
{
    
    if (!font.loadFromFile("./font/freshwost.otf"))
    {
        cout << "can not open the font" << endl;
    }
    moveCount.setFont(font);
    moveCount.setString("Move : ");
    moveCount.setCharacterSize(32);
    moveCount.setPosition(Vector2f(50 * 10 - 20,50 * 20 + 5));

    Count.setFont(font);
    Count.setCharacterSize(32);
    Count.setPosition(Vector2f(50 * 12 - 20,50 * 20 + 7));

    cout << "Enter your name : ";
    cin >> name;
}

void Game::run()
{
    moveNumber = 0;
    Player tmp;
    player = tmp;
    Map tmp1;
    map = tmp1;

    RenderWindow window(VideoMode(1050, 1050), "Game");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            } else if (Keyboard::isKeyPressed(Keyboard::A))
            {
                if (map.checkCollision('a', player.getAmbulance()))
                {
                    moveNumber++;
                    player.move('a');
                    
                }
                
            } else if (Keyboard::isKeyPressed(Keyboard::W))
            {
                if (map.checkCollision('w', player.getAmbulance()))
                {
                    player.move('w');
                    moveNumber++;
                }
            } else if (Keyboard::isKeyPressed(Keyboard::D))
            {
                if (map.checkCollision('d', player.getAmbulance()))
                {
                    player.move('d');
                    moveNumber++;
                }
            } else if (Keyboard::isKeyPressed(Keyboard::S))
            {
                if (map.checkCollision('s', player.getAmbulance()))
                {
                    player.move('s');
                    moveNumber++;
                }
            }
            

        }
        Count.setString(to_string(moveNumber / 2));
        
        window.clear();
        map.showMap(window);
        player.showPlayer(window);
        window.draw(moveCount);
        window.draw(Count);
        window.display();
        if (map.checkWin(player.getAmbulance()))
        {
            winScreen(window);
            
        }
        
    }
}

void Game::save()
{
    file.open("score.txt", ios::app | ios::out);
    file << name << "\t" << moveNumber << endl;
    file.close();
}

void Game::winScreen(RenderWindow &window)
{
    save();
    Text count;
    count.setFont(font);
    count.setString(to_string(moveNumber / 2));
    count.setCharacterSize(64);
    count.setPosition(Vector2f(620, 405));

    Text Moves;
    Moves.setFont(font);
    Moves.setString("Moves : ");
    Moves.setCharacterSize(64);
    Moves.setPosition(Vector2f(400, 400));

    Text allow;
    allow.setFont(font);
    allow.setString("Allowed moves : 100");
    allow.setCharacterSize(64);
    allow.setPosition(Vector2f(275, 500));

    Text tryAgain;
    tryAgain.setFont(font);
    tryAgain.setString("Try again");
    tryAgain.setCharacterSize(64);
    tryAgain.setPosition(Vector2f(420, 600));

    Text win;
    win.setFont(font);
    if (moveNumber / 2 < 101)
    {
        win.setString("You Win");
    } else
    {
        win.setString("You Lost");
    }
    win.setCharacterSize(64);
    win.setPosition(Vector2f(420, 300));
    
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        Vector2f mouse = window.mapPixelToCoords(Mouse::getPosition(window));

        if (tryAgain.getGlobalBounds().contains(mouse))
        {
            tryAgain.setColor(Color::Yellow);
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                window.close();
                run();   
            }
        } else
        {
            tryAgain.setColor(Color::White);
        }
        
        window.clear();
        window.draw(Moves);
        window.draw(count);
        window.draw(allow);
        window.draw(win);
        window.draw(tryAgain);
        window.display();
    }
    
    
}