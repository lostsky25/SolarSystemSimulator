#pragma once

#include "Planet.h"

class PlanetActions
{
public:
	explicit PlanetActions(std::vector<Planet*>, float);
	
	void calculatePositions(void);
	//Calculation of force vector between two planets
	sf::Vector2f forceVector(Planet*, Planet*);
	//Add new planet into vector of planets
	void addPlanet(Planet*);
	
	//Getters
	unsigned getCountOfPlanets(void);
	sf::CircleShape getItem(unsigned index);
	sf::CircleShape getSun(void);

	//Setters


	~PlanetActions();

private:
	const double G = 6.67E-11;						//Gravitational constant
	Planet *sun;									//Main star around which other planets revolve
	std::vector<Planet*> planets;					//Planets vector
	sf::Vector2f distanceVec, hatVec, forceVec;		//Vectors for calculate kept positon
	float magnitude, forceMag, dt;					//Magnitude of vector, force, delta time
};

