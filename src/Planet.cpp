#include "Planet.h"

#include <iostream>

#include "Utils.h"

sf::Vector2f Planet::getPositionFromAngle()
{
	float radian = degreeToRadian(this->angle);
	return sf::Vector2f((float)cos(radian), (float)sin(radian));
}

Planet::Planet(float r, float d)
{
	this->radius = r;
	this->distance = d;
	this->orbitSpeed = randomFloat(0.0f, 1.0f);

	float angleInRadian = randomFloat(0, 2 * M_PI);

	this->angle = radianToDegree(angleInRadian);
}

Planet::~Planet() {}

void Planet::orbit()
{
	this->angle = this->angle + this->orbitSpeed;

	if (this->planets.size() > 0)
	{
		for (int i = 0; i < this->planets.size(); i++)
		{
			this->planets[i].orbit();
		}
	}
}

void Planet::spawnChild(int total)
{
	for (int i = 0; i < total; i++)
	{
		float r = this->radius * 0.5;
		float d = randomFloat(75.0f, 300.0f);

		Planet p(r, d + this->radius);
		this->planets.push_back(p);
	}
}

void Planet::show(sf::RenderWindow &window)
{
	sf::CircleShape p(this->radius);

	sf::Vector2u size = window.getSize();

	int width = size.x;
	int height = size.y;

	float sx = constrain(0 + this->distance * cos(degreeToRadian(this->angle)), -(width/2), (width/2));
	float sy = constrain(0 + this->distance * sin(degreeToRadian(this->angle)), -(height/2), (height/2));

	sf::Vector2f pos(sx, sy);

	p.setOutlineThickness(1.0f);
	p.setOutlineColor(sf::Color::Black);
	p.setOrigin(this->radius, this->radius);
	p.setFillColor(sf::Color(255, 255, 255, 100));
	p.setPosition(pos);
	window.draw(p);

	if (this->planets.size() > 0)
	{
		for (int i = 0; i < this->planets.size(); i++)
		{
			this->planets[i].show(window);
		}
	}
}