#include "Planet.h"


//Planet::Planet()
//{
//}


Planet::Planet(float mass, float radius, sf::Vector2f position, sf::Vector2f acceleration, sf::Vector2f velocity, std::string path) {
	//this->mass = _CHANGE_MASS(mass);
	//this->radius = _CHANGE_WAY(radius);

	if (mass < 1)
	{
		//std::cout << "Balck Hole" << std::endl;
		if (radius < 1)
		{
			//std::cout << "You can\'t set less than 1 kilometers" << std::endl;
			//std::cout << "Radius was change to 1 kilometer" << std::endl;
			setRadius(1);
		}
	}
	else
	{
		this->mass = mass;
		//this->radius = radius;
		setRadius(radius);
	}

	this->position = position;
	this->acceleration = acceleration;
	this->velocity = velocity;

	setOrigin(getRadius() / 2, getRadius() / 2);
	//planetObj.setPosition(this->position);

	//setRadius(this->radius);
	setPosition(position);
	setFillColor(sf::Color::Red);



	if (!this->texture.loadFromFile(path)) {
		std::cerr << "Error load texture" << std::endl;
	}
	else
	{
		//planetObj.setPointCount(100);
		//planetObj.setTexture(&this->texture);
	}
}

//Getters
float 
Planet::getMass(void) {
	return this->mass;
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
		setRadius(radius);
}

void 
Planet::setAcceleration(sf::Vector2f acceleration) {
	this->acceleration = acceleration;
}

void 
Planet::setVelocity(sf::Vector2f velocity) {
	this->velocity = velocity;
}

Planet::~Planet()
{
}
