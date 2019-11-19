#pragma once

#include "AbstractMenu.h"

class Pause : protected AbstractMenu
{
public:
	Pause();

	/*void draw(sf::RenderWindow&, int) override;
	int selectedIndex() override;
	void moveUp() override;
	void moveDown() override;*/

	~Pause();
};

