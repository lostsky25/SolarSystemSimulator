#include "Pause.h"



Pause::Pause()
{
}

void Pause::initMenu(sf::Vector2i windowSize, std::string path) {
	this->windowSize = windowSize;

	if (!font.loadFromFile("Resources\\fonts\\Ponter.ttf"))
	{
		//handle error
	}

	if (!textureBackground.loadFromFile(path))
	{
		//handle error
	}

	active = sf::Color(52, 152, 219);
	passive = sf::Color(149, 165, 166);

	selectedItemIndex = 0;

	spriteBackground.setTexture(textureBackground);

	spriteBackground.setPosition(-windowSize.x / 2, -windowSize.y / 2);


	//spriteBackground.setOrigin(textureBackground.getSize().x / 2, textureBackground.getSize().y / 2);
	spriteBackground.setScale((float)windowSize.x / textureBackground.getSize().x,
		(float)windowSize.y / textureBackground.getSize().y);
}

void Pause::addRow(std::string text, sf::Vector2f position, sf::Vector2f scaleItem)
{
	sf::Text menuItem;
	menuItem.setFont(font);
	menuItem.setString(text);

	if (menu.empty())
		menuItem.setFillColor(active);
	else
		menuItem.setFillColor(passive);

	menuItem.setPosition(-windowSize.x / 2 + position.x, -windowSize.y / 2 + position.y);
	menuItem.setScale(scaleItem);
	menu.push_back(menuItem);
}

void Pause::draw(sf::RenderWindow& window)
{
	window.draw(spriteBackground);

	for (size_t i = 0; i < menu.size(); i++)
	{
		window.draw(menu[i]);
	}

	window.display();
}


Pause::~Pause()
{
}
