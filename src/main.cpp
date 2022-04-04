#include <SFML/Graphics.hpp>
#include <iostream>

#include "Planet.h"
#include "FPSTimer.h"

#define FRAMECAP 0

std::string title = "Space Simulation (2D)";
sf::Uint32 styleFlag = sf::Style::Default;
sf::VideoMode dimension = sf::VideoMode(1920, 1080);

FPSTimer timer;
float timerCounter = 0.0f;
unsigned int frames = 0;

sf::ContextSettings settings;

int main()
{
	settings.antialiasingLevel = 16;

	Planet sun(100, 0);
	sun.spawnChild(5);
	sf::RenderWindow window(dimension, title, styleFlag, settings);

	sf::Vector2f windowSize(window.getSize().x, window.getSize().y);
	sf::View view(sf::Vector2f(0, 0), windowSize);

	window.setView(view);
	window.setFramerateLimit(FRAMECAP);

	while (window.isOpen())
	{
		sf::Event windowEvent;

		window.clear(sf::Color(0, 0, 0, 255));
		sun.show(window);
		sun.orbit();
		window.display();

		while (window.pollEvent(windowEvent))
		{
			switch (windowEvent.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}

		frames++;
		if (timer.elapsed() - timerCounter > 1.0f)
		{
			timerCounter += 1.0f;
			printf("%d FPS\n", frames);
			frames = 0;
		}
	}

	return 0;
}