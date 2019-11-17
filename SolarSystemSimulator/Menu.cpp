#include "Menu.h"

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("Resources\\fonts\\Ponter.ttf"))
	{
		//handle error
	}

	if (!textureBackgound.loadFromFile("Resources\\img\\background-menu.jpg"))
	{
		//handle error
	}

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Start");
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Options");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 3));

	selectedItemIndex = 0;

	spriteBackground.setTexture(textureBackgound);
}

void Menu::draw(sf::RenderWindow &window) {
	
	window.draw(spriteBackground);
	
	for (size_t i = 0; i < MAX_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::moveUp() {
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::moveDown() {
	if (selectedItemIndex + 1 < MAX_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

int Menu::selectedIndex() {
	return selectedItemIndex;
}

Menu::~Menu()
{
}
