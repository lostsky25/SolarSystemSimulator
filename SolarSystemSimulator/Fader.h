#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>

class Fader
{
public:
	explicit Fader(sf::Vector2f, std::string, float, float);

	void draw(sf::RenderWindow&);

	~Fader();

private:
	sf::Clock deltaTime;
	sf::Color transparent;
	sf::Sprite spriteBackground;
	sf::Texture textureBackground;
	float fadeDt = 0.0f, timeOverload = 0.0f, alphaFade = 0.0f;
};

