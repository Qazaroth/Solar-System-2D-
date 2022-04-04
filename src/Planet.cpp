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
	this->orbitSpeed = randomFloat(-1.0f, 1.0f);

	float angleInRadian = randomFloat(0, 2 * M_PI);

	this->angle = radianToDegree(angleInRadian);
	this->isEmptyBool = false;
}

Planet::~Planet() 
{
	if (this->planets.size() > 0)
	{
		for (int i = 0; i < this->planets.size(); i++)
		{
			//delete this->planets[i];
		}
	}
}

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

void Planet::spawnChild(int total, int level)
{
	for (int i = 0; i < total; i++)
	{
		float r = this->radius / (level * 1.5);
		float d =( randomFloat(this->radius, 375.0f) + (this->radius * 2)) / level;

		this->planets.push_back(Planet(r, d));

		if (level < 3)
		{
			int numOfChild = randomInt(0, 4);
			this->planets[i].spawnChild(numOfChild, level + 1);
		}
	}
}

void Planet::show(sf::RenderWindow &window, Planet *par)
{
	sf::CircleShape p(this->radius);

	sf::Vector2u size = window.getSize();

	int width = size.x;
	int height = size.y;

	Planet parent = (*par);

	float dispX = (parent.isEmpty()) ? 0 : parent.getPosition().x;
	float dispY = (parent.isEmpty()) ? 0 : parent.getPosition().y;

	float sx = constrain(dispX + this->distance * cos(degreeToRadian(this->angle)), -(width/2), (width/2));
	float sy = constrain(dispY + this->distance * sin(degreeToRadian(this->angle)), -(height/2), (height/2));

	position.x = sx;
	position.y = sy;

	p.setOutlineThickness(1.0f);
	p.setOutlineColor(sf::Color::Black);
	p.setOrigin(this->radius, this->radius);
	p.setFillColor(sf::Color(255, 255, 255, 100));
	p.setPosition(position);
	window.draw(p);

	if (this->planets.size() > 0)
	{
		for (int i = 0; i < this->planets.size(); i++)
		{
			this->planets[i].show(window, this);
		}
	}
}