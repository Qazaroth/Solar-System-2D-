#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class Planet
{
private:
	float radius = 8.0f;
	float angle = 0.0f;
	float distance = 0.0f;
	float orbitSpeed = 0.0f;

	std::vector<Planet> planets;

	sf::Vector2f getPositionFromAngle();
public:
	Planet() {}
	Planet(float r, float d);
	~Planet();

	void orbit();

	void spawnChild(int total);
	void show(sf::RenderWindow &window);
};

