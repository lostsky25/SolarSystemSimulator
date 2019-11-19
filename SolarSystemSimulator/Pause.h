#pragma once

#include "AbstractMenu.h"

class Pause : public AbstractMenu
{
public:
	Pause();

	void draw(sf::RenderWindow&) override;
	void addRow(std::string, sf::Vector2f, sf::Vector2f) override;
	void initMenu(sf::Vector2i, std::string) override;

	~Pause();
};

