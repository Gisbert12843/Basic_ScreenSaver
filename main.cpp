#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include "random-master/include/effolkronium/random.hpp"


#include "bin/draw.h"
#include "bin/physics.h"

using Random = effolkronium::random_static;

int main()
{
	std::vector<sf::Vector2f> movementVec;
	//std::vector<sf::Sprite*> VectorOfSpritesToDraw;
	std::vector<sf::RectangleShape *> VectorOfRectsToDraw;

	double deltaWindowResolution = 0.5;
	double deltaSpritePosition = 0.0;


	//RenderWindow
	sf::RenderWindow rendWindow(sf::VideoMode(1280, 720), "My Program");
	rendWindow.setFramerateLimit(60);
	sf::Vector2u(rendWindow.getSize());

	sf::RectangleShape rect2;
	rect2.setFillColor(sf::Color::Green);
	sf::Vector2f rectPos2(400, 150);
	rect2.setPosition(rectPos2);
	rect2.setSize(sf::Vector2f(100, 100));

	for (int i = 0; i < 10; i++)
	{
		sf::RectangleShape *rect = new sf::RectangleShape;
		rect->setFillColor(sf::Color::Magenta);
		sf::Vector2f rectPos(Random::get<Random::common>(1, 1080.f), Random::get<Random::common>(1, 520.f));
		rect->setPosition(rectPos);
		rect->setSize(sf::Vector2f(60, 60));
		VectorOfRectsToDraw.push_back(rect);
		sf::Vector2f movement(Random::get<Random::common>(-4, 4.f), Random::get<Random::common>(-4, 4.f));
		movementVec.push_back(movement);
	}


	//Main Loop
	while (rendWindow.isOpen())
	{
		sf::Event event;
		while (rendWindow.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
				{
					rendWindow.close();
				}
				case sf::Event::Resized:
				{
					sf::Vector2u currentRendWindowSize = (rendWindow.getSize());
				}
				case sf::Event::KeyPressed:
				{
				}
			}
		}
		physics::collisionTest(VectorOfRectsToDraw, &rendWindow, movementVec);
		physics::moveVectorObjects(VectorOfRectsToDraw, movementVec);



		rendWindow.clear();
		drawing::drawRectangles(VectorOfRectsToDraw, &rendWindow);
		rendWindow.display();
	}


	//system("Pause");

	return 0;
}