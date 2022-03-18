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
	const int N = 200;
	const int D = 25;




	/*  sf::CircleShape shape1(100.f);
	  shape1.setFillColor(sf::Color::Black);*/


	bool f = false;
	bool p = false;
	int resolutionx = 1500;
	int resolutiony = 1500;
	// create the window
	sf::RenderWindow window(sf::VideoMode(resolutionx, resolutiony), "My window");


	int trueresolutionx = resolutionx - D * 2;
	int trueresolutiony = resolutiony - D * 2;


	int curentx = 700;
	int curenty = 1300;
	int newx = 0;
	int newy = 0;
	int dx = 5;
	int dy = 5;

	//sf::CircleShape bullets[N];

	int currentbullet = -1;
	DWORD lastBulletTime = GetTickCount64();




	//sf::RectangleShape background(sf::Vector2f(1500.f, 1500.f));

	sf::Texture textureBG;
	textureBG.loadFromFile("949c173d144f41784c1210b87ce157a0.jpg");


	sf::Sprite background;
	background.setTexture(textureBG);

	sf::Texture PlayerTexture;
	PlayerTexture.loadFromFile("player.png");


	sf::Sprite player;
	player.setTexture(PlayerTexture);

	sf::Texture Bullet;
	Bullet.loadFromFile("blaster.png");

	sf::Sprite SpaceBullet[N];






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


		// bullets flying
		for (int i = 0; i < currentbullet; i++)
		{
			SpaceBullet[i].move(0, -2);



		}

		for (int i = 0; i < currentbullet; i++)
		{
			window.draw(SpaceBullet[i]);

		}



		if (!p)
		{

			player.setScale(0.37, 0.37);
			player.setPosition(curentx, curenty);
			p = true;
		}




		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			DWORD now = GetTickCount64();

			if (currentbullet < N && now - lastBulletTime > 200)
			{
				lastBulletTime = now;
				currentbullet++;



				SpaceBullet[currentbullet].setPosition(curentx + 100, curenty);

				SpaceBullet[currentbullet].setTexture(Bullet);
			}


		}



		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			player.move(-2, 0);
			curentx = curentx - 2;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			player.move(2, 0);
			curentx = curentx + 2;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			player.move(0, -2);
			curenty = curenty - 2;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			player.move(0, 2);
			curenty = curenty + 2;
		}



		// end the current frame
		window.display();
	}

	return 0;
}

