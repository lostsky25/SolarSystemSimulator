#pragma once

#include "Simulator.h"

class Fader : protected Simulator
{
public:
	explicit Fader(sf::Vector2u, std::string, float, float);

	void draw(sf::RenderWindow&) override;

	~Fader();

private:
	sf::Texture textureLogo;
	sf::Color transparent;
	float fadeDt = 0.0f, timeOverload = 0.0f, alphaFade = 0.0f;
};

