#include "PlanetActions.h"

#include <iostream>

PlanetActions::PlanetActions(Planet* sun, std::vector<Planet*> planets, float dt) {
	this->sun = sun;
	this->dt = dt;
	this->planets = planets;
}


//Calculation of force vector between two planets
sf::Vector2f PlanetActions::forceVector(Planet* enternal, Planet* external) {

	this->distanceVec = enternal->getPosition() - external->getPosition();
	this->magnitude = std::sqrt(std::pow(distanceVec.x, 2) + std::pow(distanceVec.y, 2));
	this->hatVec = distanceVec / magnitude;
	this->forceMag = (G * enternal->getMass() * external->getMass()) / pow(magnitude, 2);
	this->forceVec = -forceMag * hatVec;

	return this->forceVec;
}

void 
PlanetActions::calculatePositions(void) {
	for (std::size_t count = 0; count < planets.size(); count++) {

		//Radius vector
		planets[count]->setRadiusVec(sqrt(pow(planets[count]->getPosition().x - sun->getPosition().x, 2) + pow(planets[count]->getPosition().y - sun->getPosition().y, 2)));

		//Calculation force between two planets
		for (size_t i = 0; i < planets.size(); i++)
		{
			if (i != count)
				force += forceVector(planets[count], planets[i]);
		}

		//Acceleration
		planets[count]->setAcceleration(sun->getMass() * (sun->getPosition() - planets[count]->getPosition()) / pow(planets[count]->getRadiusVec(), 3) + force);

		//Velocity
		planets[count]->setVelocity(planets[count]->getAcceleration() * dt);
		//Position
		planets[count]->setPosition(planets[count]->getVelocity() * dt);
	}
}

sf::CircleShape PlanetActions::getSun()
{
	return *this->sun;
}

//Add new planet into vector of planets
void
PlanetActions::addPlanet(Planet *nPlanet)
{
	planets.push_back(nPlanet);
}

//Getters
int 
PlanetActions::getCountOfPlanets(void) {
	return this->planets.size();
}

sf::CircleShape PlanetActions::getItem(unsigned index) {
	return *this->planets[index];
}



PlanetActions::~PlanetActions()
{
}
