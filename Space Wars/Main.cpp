#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "windows.h"
#include <math.h> 
#include <cmath>
#include <string>



using namespace std;


int main()
{
    const int N = 100;
    const int D = 25;

    


  /*  sf::CircleShape shape1(100.f);
    shape1.setFillColor(sf::Color::Black);*/



    bool p = false;
    int resolutionx = 1500;
    int resolutiony = 1500;
    // create the window
    sf::RenderWindow window(sf::VideoMode(resolutionx, resolutiony), "My window");


    int trueresolutionx = resolutionx - D * 2;
    int trueresolutiony = resolutiony - D * 2;

   
    int curentx = 500;
    int curenty = 500;
    int newx = 0;
    int newy = 0;
    int dx = 5;
    int dy = 5;

    sf::CircleShape bullets[N];

   


    //sf::RectangleShape background(sf::Vector2f(1500.f, 1500.f));

    sf::Texture textureBG;
    textureBG.loadFromFile("949c173d144f41784c1210b87ce157a0.jpg");


    sf::Sprite background;
    background.setTexture(textureBG);

    sf::Texture PlayerTexture;
    PlayerTexture.loadFromFile("player.png");


    sf::Sprite player;
    player.setTexture(PlayerTexture);


    for (int i = 0; i < N; i++)
    {
        bullets[i] = sf::CircleShape(D);
        bullets[i].setFillColor(sf::Color(150, 50, 250));



    }




    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Cyan);

        window.draw(background);
        sf::FloatRect boundingBox1 = background.getGlobalBounds();
        window.draw(player);
        sf::FloatRect boundingBox2 = player.getGlobalBounds();

        
       
        if (!p)
        {
            player.setScale(0.37, 0.37);
            player.setPosition(700, 1300);
            p = true;
        }
        
        



            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                player.move(-2, 0);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                player.move(2, 0);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                player.move(0, -2);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                player.move(0, 2);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {

            }

        



        

        

       

            
        



        

        // end the current frame
        window.display();
    }

    return 0;
}

