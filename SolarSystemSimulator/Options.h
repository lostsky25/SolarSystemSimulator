#pragma once

#include "AbstractMenu.h"

class Options : public AbstractMenu
{
public:
	Options();

	void initMenu(sf::Vector2i, std::string) override;
	void updateParallaxBackground(sf::Vector2f positionMouse, int gainParallax) override;
	
	~Options();
};

