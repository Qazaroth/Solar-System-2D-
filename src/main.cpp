#include <SFML/Graphics.hpp>

#include "FPSTimer.h"

#define FRAMECAP 60

std::string title = "Space Simulation (2D)";
sf::Uint32 styleFlag = sf::Style::Default;

FPSTimer timer;
float timerCounter = 0.0f;
unsigned int frames = 0;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), title, styleFlag);

	window.setFramerateLimit(FRAMECAP);

	while (window.isOpen())
	{
		sf::Event windowEvent;

		window.clear();
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