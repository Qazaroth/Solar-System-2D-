#pragma once

#define _USE_MATH_DEFINES

#include <math.h>

#include <ctime>
#include <random>
#include <SFML/Graphics.hpp>

inline float radianToDegree(float angle)
{
	return angle * (180 / M_PI);
}

inline float degreeToRadian(float angle)
{
	return angle * (M_PI / 180);
}

int static randomInt(int min, int max)
{
	//srand(time(0));
	return (rand() % max) + min;//min + (std::rand() % (max - min + 1));
}

static float dist(const sf::Vector2f p1, const sf::Vector2f p2)
{
	float diffY = p1.y - p2.y;
	float diffX = p1.x - p2.x;
	return sqrt((diffY * diffY) + (diffX * diffX));
}

float static randomFloat(float min, float max)
{
	//srand(static_cast<unsigned>(time(0)));
	return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

static float constrain(float value, float min, float max)
{
	if (value <= min) value = min;
	if (value >= max) value = max;

	return value;
}

int static map(float value, float start1, float stop1, float start2, float stop2)
{
	return start2 + (stop2 - start2) * ((value - start1) / (stop1 - start1));
}