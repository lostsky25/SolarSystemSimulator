#include "ImGUI/imgui.h"
#include "ImGUI/imgui-SFML.h"

#include "PlanetActions.h"
#include "Menu.h"
#include "Fader.h"

#if _MSC_VER >= 1800
	#include <Windows.h>
#else
	#include <iostream>
#endif // !_MSC_VER >= 1800

static const short width = 1920;
static const short height = 1080;

int main(int argc, char **argv) {
	Planet testPlanet(10, 200, sf::Vector2f(0,0), sf::Vector2f(0, 0), sf::Vector2f(0, 0), "p");

	float mouseDelta = 200, radiusScaleUnits = 1300, ScaleX, ScaleY;
	float color[3] = { 0.0f, 0.0f, 0.0f };
	const float minMouseDelta = 50;

	sf::Color backgroundColor, oldBackgroundColor;
	sf::Vector2i mousePosition(0, 0); 
	sf::Texture BackgroundTexture;
	sf::Sprite background;
	sf::Vector2u TextureSize;
	sf::Vector2f WindowSize;
	sf::Clock deltaTime;	
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(width, height),
		"Solar System Simulator",
		sf::Style::Fullscreen,
		settings);


	/*Fader fadeMainLogo(window.getSize(), "Resources\\img\\main-logo.jpg", 3.0f, 0.001f);
	fadeMainLogo.draw(window);
*/
	//Fader fadeLogo(window.getSize(), "Resources\\img\\solar-system-simulator-logo.jpg", 3.0f, 0.001f);
	//fadeLogo.draw(window);
	
	/*Fader fadeWarning(window.getSize(), "Resources\\img\\background-epileptic.jpg", 5.0f, 0.001f);
	fadeWarning.draw(window);
*/
	Menu menu(window.getSize().x, window.getSize().y);

	sf::View view(sf::Vector2f(width, height), sf::Vector2f(width * mouseDelta, height * mouseDelta));
	window.setVerticalSyncEnabled(true);
	
	if (!BackgroundTexture.loadFromFile("Resources\\img\\starsMilkyWay.jpg")){
		#if _MSC_VER >= 1800
			OutputDebugString(L"Background texture wasn\'t opened\r\n");
		#else
			std::cerr << "Background texture wasn\'t opened" << std::endl;
		#endif // !_MSC_VER >= 1800

		return EXIT_FAILURE;
	}else{
		TextureSize = BackgroundTexture.getSize();
		WindowSize = view.getSize();

		background.setOrigin(sf::Vector2f(TextureSize.x / 2, TextureSize.y / 2));

		ScaleX = (float)WindowSize.x / TextureSize.x;
		ScaleY = (float)WindowSize.y / TextureSize.y;

		background.setTexture(BackgroundTexture);
	}

	ImGui::SFML::Init(window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			ImGui::SFML::ProcessEvent(event);

			if (event.type == sf::Event::KeyReleased)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.moveUp();
					break;
				case sf::Keyboard::Down:
					menu.moveDown();
					break;
				case sf::Keyboard::Enter:
					std::cout << "Entered item: " << menu.selectedIndex() << std::endl;
					switch (menu.selectedIndex())
					{
					case 0:

						break;
					case 1:

						break;
					case 2:
						window.close();
						break;
					default:
						break;
					}
					break;
				default:
					break;
				}
			}

			if (event.type == sf::Event::KeyPressed) {
				switch (event.key.code)
				{
				case sf::Keyboard::Escape: {
					window.close();
					break;
				}
				default:
					break;
				}
			}
		}

		/*ImGui::SFML::Update(window, deltaTime.restart());

		ImGui::Begin("Solar System Configure");

		ImGui::LabelText("text", "text");
		ImGui::End();
		*/
		//window.draw(background);

		//ImGui::SFML::Render(window);

		//window.draw(testPlanet);

		menu.draw(window);

		window.display();
	}

	ImGui::SFML::Shutdown();

	return 0;
}