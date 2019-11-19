#include "PlanetActions.h"

PlanetActions::PlanetActions(std::vector<Planet*> planets, float dt) {
	if (planets.size() < 2)
	{

	}
	else {

	}
}

void 
PlanetActions::calculatePositions(void) {

}

//Calculation of force vector between two planets
sf::Vector2f 
PlanetActions::forceVector(Planet* in, Planet* ex) {
	return sf::Vector2f();
}

//Add new planet into vector of planets
void 
PlanetActions::addPlanet(Planet* nPlanet) {

}

//Getters
unsigned 
PlanetActions::getCountOfPlanets(void) {
	return unsigned();
}

sf::CircleShape PlanetActions::getItem(unsigned index) {
	return sf::CircleShape();
}

sf::CircleShape PlanetActions::getSun(void) {
	return sf::CircleShape();
}


PlanetActions::~PlanetActions()
{
}
