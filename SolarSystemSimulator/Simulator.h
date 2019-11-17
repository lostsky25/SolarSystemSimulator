#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

class Simulator
{
public:
	Simulator();
	~Simulator();

protected:
	virtual void draw(sf::RenderWindow&);

	sf::Clock deltaTime;
	sf::Sprite spriteBackground;
};

