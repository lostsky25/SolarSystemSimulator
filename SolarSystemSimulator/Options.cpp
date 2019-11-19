#include "Options.h"



Options::Options()
{
}

void Options::initMenu(sf::Vector2i windowSize, std::string path) {
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
}

void Options::updateParallaxBackground(sf::Vector2f positionMouse, int gainParallax) {
	
}

Options::~Options()
{
}
