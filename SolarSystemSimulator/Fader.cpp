#include "Fader.h"

Fader::Fader(sf::Vector2f windowSize, std::string pathLogo, float timeOverload, float fadeDt)
{
	this->timeOverload = timeOverload;
	this->fadeDt = fadeDt;

	transparent = sf::Color::Black;
	transparent.a = 0;

	if (!textureBackground.loadFromFile(pathLogo))
	{

	}

	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(sf::Vector2f(-windowSize.x / 2, -windowSize.y / 2));
	spriteBackground.setScale((float)windowSize.x * 1.01 / textureBackground.getSize().x,
		(float)windowSize.y * 1.01 / textureBackground.getSize().y);


}

void Fader::draw(sf::RenderWindow& window) {
	while (deltaTime.getElapsedTime().asSeconds() < timeOverload && window.isOpen())
	{
		window.draw(spriteBackground);
		spriteBackground.setColor(transparent);

		window.display();
	}

	while (alphaFade < 250 && window.isOpen())
	{
		alphaFade += fadeDt * 255;
		transparent.a = static_cast<sf::Uint8>(alphaFade);

		window.draw(spriteBackground);
		spriteBackground.setColor(transparent);

		window.display();
	}
}


Fader::~Fader()
{
}