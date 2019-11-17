#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include <limits.h>
#include <math.h>

//#define _CHANGE_MASS(MASS) (MASS / 1.989E30 * 600000)
//#define _CHANGE_WAY(WAY) (WAY / 2000)
//#define _CHANGE_RADIUS(RADIUS) (RADIUS / 200)

class Planet : public sf::CircleShape
{
public:
	explicit Planet(float, float, sf::Vector2f, sf::Vector2f, sf::Vector2f, std::string);

	//Getters
	float getMass(void);
	float getRadiusVec(void);
	//sf::Vector2f getPosition(void);
	sf::Vector2f getAcceleration(void);
	sf::Vector2f getVelocity(void);
	
	//Setters
	void setMass(float);
	void setRadiusVec(float);
	//void setPosition(sf::Vector2f);
	void setAcceleration(sf::Vector2f);
	void setVelocity(sf::Vector2f);

	//Other methods
	void addRadius(float);

	~Planet();

private:
	float mass;											//in kilograms
	//float radius;										//in kilometers
	float radiusVec;									//UNITS
	sf::Texture texture;								//Picture (png, jpg, jpeg, tfif)
	sf::Vector2f position, acceleration, velocity;		//Movement mechanics
};

