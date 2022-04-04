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

	bool isEmptyBool = false;

	std::vector<Planet> planets;

	sf::Vector2f position;

	sf::Vector2f getPositionFromAngle();
public:
	Planet() { this->isEmptyBool = true; }
	Planet(float r, float d);
	~Planet();

	void orbit();

	void spawnChild(int total, int level);
	void show(sf::RenderWindow &window, Planet *parent);

	inline bool isEmpty() { return this->isEmptyBool; }
	inline sf::Vector2f getPosition() { return position; }
};

