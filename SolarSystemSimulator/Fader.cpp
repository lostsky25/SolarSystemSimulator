#include "Fader.h"

Fader::Fader(sf::Vector2u windowSize, std::string pathLogo, float timeOverload, float fadeDt)
{
	this->timeOverload = timeOverload;
	this->fadeDt = fadeDt;

	transparent = sf::Color::Black;
	transparent.a = 0;

	
	//textureLogo.setSmooth(true);

	if (!textureLogo.loadFromFile(pathLogo))
	{

	}

	spriteBackground.setTexture(textureLogo);
	spriteBackground.setScale((float)windowSize.x / textureLogo.getSize().x,
		(float)windowSize.y / textureLogo.getSize().y);


}

void 
Fader::draw(sf::RenderWindow& window)
{
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
