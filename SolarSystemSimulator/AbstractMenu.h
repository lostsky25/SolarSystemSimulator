#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

//#include "Simulator.h"

class AbstractMenu// : protected Simulator
{
public:
	virtual void draw(sf::RenderWindow&);
	virtual void initMenu(sf::Vector2i, std::string);
	virtual void addRow(std::string, sf::Vector2f, sf::Vector2f);
	virtual int selectedIndex();
	virtual void updateParallaxBackground(sf::Vector2f, int);
	virtual void moveUp();
	virtual void moveDown();

	int selectedItemIndex, rows, columns;
	sf::Color active, passive;
	sf::Vector2i windowSize;
	sf::Sprite spritePanel, spriteBackground;
	sf::Texture texturePanel, textureBackground;
	sf::Font font;
	std::vector<sf::Text> menu;
};

