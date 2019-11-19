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

	//spritePanel.setTexture(texturePanel);
	spriteBackground.setTexture(textureBackground);

	//spritePanel.setPosition(-windowSize.x / 2, -windowSize.y / 2);
	spriteBackground.setPosition(-windowSize.x / 2, -windowSize.y / 2);

}

Options::~Options()
{
}
