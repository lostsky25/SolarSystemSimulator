#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

class Render : public sf::RenderWindow
{
public:
	//Render();
	explicit Render(sf::Vector2f, std::string);
	sf::Clock getDeltaTime();
	//void draw(sf::RenderWindow&) override;
	~Render();

private:
	float mouseDelta = 200, radiusScaleUnits = 1300, ScaleX, ScaleY, color[3] = { 0.0f, 0.0f, 0.0f };
	const float minMouseDelta = 50;

	//Window and context
	//sf::Vector2f WindowSize;
	sf::ContextSettings settings;

	sf::Color backgroundColor, oldBackgroundColor;
	sf::Vector2i mousePosition;
	sf::Vector2u textureSize;

	//Event
	//sf::Event event;

	sf::Clock deltaTime;
	sf::Sprite spriteBackground;
	sf::Texture textureBackground;

};