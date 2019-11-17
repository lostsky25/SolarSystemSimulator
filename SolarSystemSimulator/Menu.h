#pragma once

#include "Simulator.h"

#define MAX_ITEMS 3

class Menu : protected Simulator
{
public:
	Menu(float width, float height);

	void draw(sf::RenderWindow &window) override;
	int selectedIndex();
	void moveUp();
	void moveDown();

	~Menu();

private:
	int selectedItemIndex;
	sf::Texture textureBackgound;
	sf::Font font;
	sf::Text menu[MAX_ITEMS];
};

