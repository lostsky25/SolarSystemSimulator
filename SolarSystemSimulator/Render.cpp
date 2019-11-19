#include "Render.h"

Render::Render(sf::Vector2f windowSize, std::string windowPath)
{
	deltaTime.restart();
	settings.antialiasingLevel = 8;
	create(sf::VideoMode(windowSize.x, windowSize.y), "Solar System Simulator", sf::Style::Fullscreen, settings);

	//sf::View view(sf::Vector2f(windowSize.x / 2, windowSize.y / 2),
		//sf::Vector2f(windowSize.x , windowSize.y ));
	//setView(view);
	//setVerticalSyncEnabled(true);
}

sf::Clock Render::getDeltaTime() {
	return deltaTime;
}

Render::~Render()
{
}
