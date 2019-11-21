#include "Planet.h"

Planet::Planet(float mass, float radius, sf::Vector2f position, sf::Vector2f acceleration, sf::Vector2f velocity, std::string path) {
	this->mass = _CHANGE_MASS(mass);
	this->radius = _CHANGE_RADIUS(radius);
	this->position.x = _CHANGE_WAY(position.x);
	this->position.y = _CHANGE_WAY(position.y);

	this->acceleration = acceleration;
	this->velocity = velocity;
	
	setPosition(this->position);
	setRadius(this->radius);
	setOrigin(this->radius / 2, this->radius / 2);

	if (!this->texture.loadFromFile(path)) {
		//std::cerr << "Error load texture" << std::endl;
	}
	else
	{
		setTexture(&this->texture);
	}
}

//Getters
sf::Vector2f Planet::getPosition(void) {
	return this->position;
}

float 
Planet::getMass(void) {
	return this->mass;
}

float Planet::getRadius(void)
{
	return this->radius;
}

float 
Planet::getRadiusVec(void) {
	return this->radiusVec;
}

sf::Vector2f 
Planet::getAcceleration(void) {
	return this->acceleration;
}

sf::Vector2f 
Planet::getVelocity(void) {
	return this->velocity;
}

//Setters
void 
Planet::setMass(float mass) {
	if (mass > 1)
		this->mass = mass;
	else
	{
		//std::cout << "Black Hole was created" << std::endl;
		this->mass = -1;
	}
}

void Planet::setDefaultRadius(void)
{
	setRadius(this->radius);
}

void 
Planet::setRadiusVec(float radiusVec) {
	this->radiusVec = radiusVec;
}

void 
Planet::addRadius(float radius) {
	if (radius < 1)
	{
		//std::cout << "You can\'t set less than 1 kilometers" << std::endl;
		//std::cout << "Radius was change to 1 kilometer" << std::endl;
		//this->radius = 1;
		setRadius(1);
	}else
		setRadius(getRadius() + radius);
}

void 
Planet::setAcceleration(sf::Vector2f acceleration) {
	this->acceleration = acceleration;
}

void
Planet::setPosition(sf::Vector2f position) {
	this->position += position;
	sf::Transformable::setPosition(this->position);
}

void 
Planet::setVelocity(sf::Vector2f velocity) {
	this->velocity += velocity;
}

Planet::~Planet()
{
}
