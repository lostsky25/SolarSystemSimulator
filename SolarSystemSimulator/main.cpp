#include "ImGUI/imgui.h"
#include "ImGUI/imgui-SFML.h"

#include "PlanetActions.h"

#if _MSC_VER >= 1800
	#include <Windows.h>
#else
	#include <iostream>
#endif // !_MSC_VER >= 1800

static const short width = 1920;
static const short height = 1080;

int main(int argc, char **argv) {

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

	sf::View view(sf::Vector2f(width, height), sf::Vector2f(width * mouseDelta, height * mouseDelta));
	window.setVerticalSyncEnabled(true);
	
	if (!BackgroundTexture.loadFromFile("Resources\\starsMilkyWay.jpg")){
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

		ImGui::SFML::Update(window, deltaTime.restart());

		ImGui::Begin("Solar System Configure");

		ImGui::LabelText("text", "text");
		ImGui::End();

		window.draw(background);

		ImGui::SFML::Render(window);

		window.display();
	}

	ImGui::SFML::Shutdown();

	return 0;
}