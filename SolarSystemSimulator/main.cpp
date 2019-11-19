#include "ImGUI/imgui.h"
#include "ImGUI/imgui-SFML.h"

#include "Render.h"
#include "PlanetActions.h"
#include "Menu.h"
#include "Fader.h"
#include "Options.h"

#include <iostream>

#if _MSC_VER >= 1800
	#include <Windows.h>
#else
	#include <iostream>
#endif // !_MSC_VER >= 1800

static const float width = 1920;
static const float height = 1080;
static const int gainParallax = 50;
static const int scaleSize = 200;

int main(int argc, char **argv) {
	///Background picture
	bool backgroundImageState = true;
	bool backgroundSolidColorState = false;

	bool gameLoop = false;
	bool gameMenu = true;
	bool gameOptions = false;

	float color[3] = { 0.0f, 0.0f, 0.0f };
	float radiusScaleUnits = 0.0f;

	sf::Color bgColor, oldBgColor;
	
	sf::Vector2f viewPortSize(width * scaleSize, height * scaleSize);
	sf::Vector2f windowSize(width, height);

	Planet testPlanet(10, 200, sf::Vector2f(0,0), sf::Vector2f(0, 0), sf::Vector2f(0, 0), "p");

	Render simulator(windowSize, "Solar System Simulator");
	simulator.setView(sf::View(windowSize, viewPortSize));
	simulator.setVerticalSyncEnabled(true);
	
	///First (main logo)
	//Fader fadeMainLogo(viewPortSize, "Resources\\img\\main-logo.jpg", 3.0f, 0.001f);
	//fadeMainLogo.draw(simulator);

	///Second (warning)
	//Fader fadeWarning(viewPortSize, "Resources\\img\\background-epileptic.jpg", 5.0f, 0.001f);
	//fadeWarning.draw(simulator);
	
	///Menu
	Menu menu;
	menu.initMenu(sf::Vector2i(width * scaleSize, height * scaleSize), "Resources\\img\\stars.jpg");

	menu.addRow("Start", sf::Vector2f(15000, 900 * scaleSize / 2), sf::Vector2f(scaleSize, scaleSize));
	menu.addRow("Options", sf::Vector2f(15000, 1200 * scaleSize / 2), sf::Vector2f(scaleSize, scaleSize));
	menu.addRow("Exit", sf::Vector2f(15000, 1500 * scaleSize / 2), sf::Vector2f(scaleSize, scaleSize));

	///Options
	/*Options options;
	options.initMenu(sf::Vector2i(width * scaleSize, height * scaleSize), "Resources\\img\\stars.jpg");

	menu.addRow("Start", sf::Vector2f(15000, 900 * scaleSize / 2), sf::Vector2f(scaleSize, scaleSize));
	menu.addRow("Options", sf::Vector2f(15000, 1200 * scaleSize / 2), sf::Vector2f(scaleSize, scaleSize));
	menu.addRow("Exit", sf::Vector2f(15000, 1500 * scaleSize / 2), sf::Vector2f(scaleSize, scaleSize));
*/
	///Set view port
	//simulator.setView(sf::View(sf::Vector2f(width, height), sf::Vector2f(width * 200, height * 200)));
	//simulator.setVerticalSyncEnabled(true);

	sf::Clock deltaTime;
	deltaTime.restart();
	///ImGui library intialize
	ImGui::SFML::Init(simulator);

	while (simulator.isOpen())
	{
		sf::Event event;
		while (simulator.pollEvent(event))
		{
			///ImGui library events
			ImGui::SFML::ProcessEvent(event);
			///menu
			if (event.type == sf::Event::KeyReleased && gameMenu){
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.moveUp();
					break;
				case sf::Keyboard::Down:
					menu.moveDown();
					break;
				case sf::Keyboard::Enter:
					///Start
					if (menu.selectedIndex() == 0)
					{
						gameLoop = true;
						gameMenu = !gameLoop;
						simulator.clear();
					}
					///Options
					else if (menu.selectedIndex() == 1)
					{
						//gameLoop = false;
						//gameMenu = false; //why?
						//gameOptions = true;
						//simulator.clear();

					}
					///Exit
					else if (menu.selectedIndex() == 2) {
						simulator.close();
					}

					break;
				default:
					break;
				}
			}else if (event.type == sf::Event::KeyReleased){
				switch (event.key.code)
				{
				case sf::Keyboard::Escape:{
					///Pause class
					gameMenu = true;
					gameLoop = false;
					simulator.clear();
					break;
				}
				case sf::Keyboard::Up:
					break;
				case sf::Keyboard::Down:
					break;
				case sf::Keyboard::Enter:
					break;
				default:
					break;
				}
			} ///End menu


		}

		if (gameMenu) {
			menu.draw(simulator);
			menu.updateParallaxBackground(sf::Vector2f(sf::Mouse::getPosition().x * gainParallax,
				sf::Mouse::getPosition().y * gainParallax), gainParallax);
		}

		if (gameLoop){
			///ImGui interface
			ImGui::SFML::Update(simulator, deltaTime.restart());

			ImGui::Begin("Solar System Configure");
		/*
				if (ImGui::ColorEdit3("Background color", color)) {
					bgColor.r = static_cast<sf::Uint8>(color[0] * 255.f);
					bgColor.g = static_cast<sf::Uint8>(color[1] * 255.f);
					bgColor.b = static_cast<sf::Uint8>(color[2] * 255.f);
				}

				if (ImGui::Checkbox("Backgroud Image", &backgroundImageState))
					//background.setScale(ScaleX * mouseDelta / minMouseDelta, ScaleY * mouseDelta / minMouseDelta);


				if (ImGui::Checkbox("Background Solid Color", &backgroundSolidColorState)) {
					simulator.clear(bgColor);
				}

				if (!backgroundSolidColorState)
				{
					bgColor = { 0, 0, 0 };
				}

				if (ImGui::Checkbox("Show Orbit Path", &showOrbitPathState))
				{
					for (size_t count = 0; count < curve.size(); count++)
					{
						curve[count].clear();
					}
				}
	*/
				ImGui::LabelText("", "Planets config:");

				ImGui::SliderFloat("Radius (units scale):", &radiusScaleUnits, 0, 25000);

			ImGui::End();

			///ImGui interface end

			simulator.clear(bgColor);

			///Draw planets
			simulator.draw(testPlanet);

			ImGui::SFML::Render(simulator);

		}

		///Game options
		/*if (gameOptions)
		{
			options.draw(simulator);
		}*/

		simulator.display();
	}

	ImGui::SFML::Shutdown();

	return 0;
}