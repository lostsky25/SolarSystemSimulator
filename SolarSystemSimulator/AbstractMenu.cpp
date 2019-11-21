#include "AbstractMenu.h"

void AbstractMenu::initMenu(sf::Vector2i windowSize, std::string path) {
	this->windowSize = windowSize;
	
	if (!font.loadFromFile("Resources\\fonts\\Ponter.ttf"))
	{
		//handle error
	}

	if (!texturePanel.loadFromFile("Resources\\img\\menu-panel.png"))
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

	spritePanel.setTexture(texturePanel);
	spriteBackground.setTexture(textureBackground);
	
	spritePanel.setPosition(-windowSize.x / 2, -windowSize.y / 2);
	spriteBackground.setPosition(-windowSize.x / 2, -windowSize.y / 2);
}

void AbstractMenu::addRow(std::string text, sf::Vector2f position, sf::Vector2f scaleItem)
{
	sf::Text menuItem;
	menuItem.setFont(font);
	menuItem.setString(text);
	//menuItem.setScale(sf::Vector2f(100, 100));
	
	if (menu.empty())
		menuItem.setFillColor(active);
	else
		menuItem.setFillColor(passive);

	menuItem.setPosition(-windowSize.x / 2 + position.x, -windowSize.y / 2 + position.y);
	menuItem.setScale(scaleItem);
	menu.push_back(menuItem);
}

void AbstractMenu::updateParallaxBackground(sf::Vector2f positionMouse, int gainParallax) {
	spriteBackground.setPosition(positionMouse.x + gainParallax, 
		positionMouse.y + gainParallax);

	/*
	spriteBackground.setPosition(positionMouse.x + gainParallax - windowSize.x / 2, 
		positionMouse.y + gainParallax - windowSize.y / 2);
	*/

	spriteBackground.setOrigin(textureBackground.getSize().x / 2, textureBackground.getSize().y / 2);
	spriteBackground.setScale((float)windowSize.x * 2 / textureBackground.getSize().x,
		(float)windowSize.y * 2 / textureBackground.getSize().y);
	spritePanel.setScale((float)windowSize.x / texturePanel.getSize().x,
		(float)windowSize.y / texturePanel.getSize().y);
}

void AbstractMenu::draw(sf::RenderWindow& window)
{
	window.draw(spriteBackground);
	window.draw(spritePanel);

	for (size_t i = 0; i < menu.size(); i++)
	{
		window.draw(menu[i]);
	}

	window.display();
}

void AbstractMenu::moveUp() {
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(passive);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(active);
	}
}

void AbstractMenu::moveDown() {
	if (selectedItemIndex + 1 < menu.size())
	{
		menu[selectedItemIndex].setFillColor(passive);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(active);
	}
}

int AbstractMenu::selectedIndex() {
	return selectedItemIndex;
}
