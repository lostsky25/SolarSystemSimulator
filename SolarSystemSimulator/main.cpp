#include "ImGUI/imgui.h"
#include "ImGUI/imgui-SFML.h"

#include "Render.h"
#include "PlanetActions.h"
#include "Menu.h"
#include "Fader.h"
#include "Options.h"
#include "Pause.h"

#include <iostream>
#include <filesystem>

#if _MSC_VER >= 1800
	#include <Windows.h>
#else
	#include <iostream>
#endif // !_MSC_VER >= 1800

static const float width = 1920;
static const float height = 1080;
static const int gainParallax = 50;
static const int scaleSize = 200;
//static const int scalePlanet = 1;

int main(int argc, char **argv) {
	
	std::string path = "Resources\\img\\Planets";

	std::vector<std::string> packImagesPath;
	sf::Texture texturePackImage[100]; //Fixed size ???
	sf::Sprite spritePackImage[100];   //Fixed size ???
	
	int packItem = 0;

	for (const auto & entry : std::experimental::filesystem::directory_iterator(path))
		packImagesPath.push_back(entry.path().string());

	for (size_t count = 0; count < packImagesPath.size(); count++)
	{
		texturePackImage[count].loadFromFile(packImagesPath[count]);
		spritePackImage[count].setTexture(texturePackImage[count]);
	}
	
	char newMassBuffer[30] = { 0 };
	char newRadiusBuffer[30] = { 0 };

	int newMass = 0;
	int newRadius = 0;

	bool defaultRadiusState = false;

	///Background picture
	bool backgroundImageState = true;
	bool backgroundSolidColorState = false;

	bool _simulatorLoop = false;
	bool _simulatorMenu = true;
	bool _simulatorOptions = false;
	bool _simulatorPause = false;

	float color[3] = { 0.0f, 0.0f, 0.0f };
	const float minMouseDelta = 200;
	float radiusScaleUnits = 0.0f;
	float mouseDelta = 200;

	sf::Vector2f speedScaleUnits(0, 0);

	sf::Color bgColor, oldBgColor;

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	sf::Vector2u TextureSize;  //Added to store texture size.
	sf::Vector2f WindowSize;   //Added to store window size.

	float ScaleX;
	float ScaleY;

	Render simulator(sf::Vector2f(width, height), "Solar System Simulator");

	sf::View view(sf::Vector2f(width, height), sf::Vector2f(width * mouseDelta, height * mouseDelta));
	simulator.setView(view);
	simulator.setVerticalSyncEnabled(true);

	if (!backgroundTexture.loadFromFile("Resources\\img\\starsMilkyWay.jpg"))
	{

	}
	else
	{
		TextureSize = backgroundTexture.getSize(); //Get size of texture.
		WindowSize = view.getSize();             //Get size of window.

		backgroundSprite.setOrigin(sf::Vector2f(TextureSize.x / 2, TextureSize.y / 2));

		ScaleX = (float)WindowSize.x / TextureSize.x;
		ScaleY = (float)WindowSize.y / TextureSize.y;     //Calculate scale.

		backgroundSprite.setTexture(backgroundTexture);
		backgroundSprite.setScale(ScaleX * mouseDelta / minMouseDelta, ScaleY * mouseDelta / minMouseDelta);
	}

	//Planets
	Planet *sun = new Planet(1.989E30, 695510, sf::Vector2f(0, -2000), sf::Vector2f(0, 0), sf::Vector2f(0, 0), "Resources\\img\\Planets\\sun.jpg");

	Planet *mercury = new Planet(3.285E23, 2439.7, sf::Vector2f(0, -57910000), sf::Vector2f(0, 0), sf::Vector2f(4.1, 0.3), "Resources\\img\\Planets\\mercury.jpg");
	Planet *venera = new Planet(4.867E24, 6051.8, sf::Vector2f(0, -108200000), sf::Vector2f(0, 0), sf::Vector2f(2.9, 0.5), "Resources\\img\\Planets\\venera.jpg");
	Planet *earth = new Planet(5.972E24, 6371, sf::Vector2f(0, -149600000), sf::Vector2f(0, 0), sf::Vector2f(2.5, 0.5), "Resources\\img\\Planets\\earth.jpg");

	std::vector<Planet*> listPlanets;
	listPlanets.push_back(mercury);
	listPlanets.push_back(venera);
	listPlanets.push_back(earth);

	//For mouse
	sf::Vector2f mouseScalePosition;

	PlanetActions pla(sun, listPlanets, 1000.0f);
	
	///First (main logo)
	Fader fadeMainLogo(view.getSize(), "Resources\\img\\main-logo.jpg", 3.0f, 0.001f);
	fadeMainLogo.draw(simulator);

	///Second (warning)
	Fader fadeWarning(view.getSize(), "Resources\\img\\background-epileptic.jpg", 5.0f, 0.001f);
	fadeWarning.draw(simulator);
	
	///Menu
	Menu menu;
	menu.initMenu(sf::Vector2i(width * scaleSize, height * scaleSize), "Resources\\img\\stars.jpg");

	menu.addRow("Start", sf::Vector2f(15000, 900 * scaleSize / 2), sf::Vector2f(scaleSize, scaleSize));
	//menu.addRow("Options", sf::Vector2f(15000, 1000 * scaleSize / 2), sf::Vector2f(scaleSize, scaleSize));
	menu.addRow("Exit", sf::Vector2f(15000, 1200 * scaleSize / 2), sf::Vector2f(scaleSize, scaleSize));

	///Options
	/*Options options;
	options.initMenu(sf::Vector2i(width * scaleSize, height * scaleSize), "Resources\\img\\stars.jpg");

	options.addRow("Resolution", sf::Vector2f(15000, 900 * scaleSize / 2), sf::Vector2f(scaleSize, scaleSize));
	options.addRow("Graphics", sf::Vector2f(15000, 1000 * scaleSize / 2), sf::Vector2f(scaleSize, scaleSize));
	options.addRow("Cancel", sf::Vector2f(15000, 1200 * scaleSize / 2), sf::Vector2f(scaleSize, scaleSize));*/

	Pause pause;
	pause.initMenu(sf::Vector2i(width * scaleSize, height * scaleSize), "Resources\\img\\pause.png");

	pause.addRow("Resume", sf::Vector2f(16000, 1100 * scaleSize / 2), sf::Vector2f(scaleSize, scaleSize));
	//pause.addRow("Options", sf::Vector2f(16000, 1200 * scaleSize / 2), sf::Vector2f(scaleSize, scaleSize));
	pause.addRow("Exit", sf::Vector2f(16000, 1400 * scaleSize / 2), sf::Vector2f(scaleSize, scaleSize));

	///Set view port
	//simulator.setView(sf::View(sf::Vector2f(width, height), sf::Vector2f(width * 200, height * 200)));
	//simulator.setVerticalSyncEnabled(true);
	
	///ImGui library intialize
	ImGui::SFML::Init(simulator);
	bool imGuiHasFocus;

	while (simulator.isOpen())
	{
		sf::Event event;
		while (simulator.pollEvent(event))
		{
			///ImGui library events
			ImGui::SFML::ProcessEvent(event);
			
			imGuiHasFocus = !ImGui::IsWindowFocused(ImGuiFocusedFlags_AnyWindow);

			if ((event.type == sf::Event::MouseButtonPressed) && _simulatorLoop && imGuiHasFocus)
			{
				Planet *temp = new Planet(
					newMass,
					newRadius,
					sf::Vector2f(mouseScalePosition.x * view.getSize().x / mouseDelta / 2, mouseScalePosition.y * view.getSize().x / mouseDelta / 2),
					sf::Vector2f(0, 0), speedScaleUnits,
					packImagesPath[packItem]);

				listPlanets.push_back(temp);
				pla.addPlanet(temp);

			}

			///menu
			/*
			_simulatorLoop
			_simulatorMenu
			_simulatorOptions
			*/
			if (event.type == sf::Event::MouseWheelMoved && _simulatorLoop)
			{
				if (mouseDelta < minMouseDelta)
					mouseDelta = minMouseDelta;
				else
					mouseDelta += event.mouseWheel.delta * 15;

				if (backgroundImageState)
					backgroundSprite.setScale(ScaleX * mouseDelta / minMouseDelta, ScaleY * mouseDelta / minMouseDelta);

				view.reset(sf::FloatRect(sf::Vector2f(width, height), sf::Vector2f(width * mouseDelta, height * mouseDelta)));
				view.setCenter(sf::Vector2f(-width, -height));
				simulator.setView(view);
			}

			if (event.type == sf::Event::MouseMoved && _simulatorLoop)
			{
				mouseScalePosition = sf::Vector2f(sf::Mouse::getPosition().x * mouseDelta - mouseDelta * width / 2, sf::Mouse::getPosition().y * mouseDelta - mouseDelta * height / 2);
			}

			if (event.type == sf::Event::KeyReleased) {
				switch (event.key.code)
				{
				case sf::Keyboard::Up: {
					if (_simulatorMenu)
					{
						menu.moveUp();
					}
					/*else if (_simulatorOptions) {
						options.moveUp();
					}*/
					else if (_simulatorPause) {
						pause.moveUp();
					}
					break;
				}
				case sf::Keyboard::Down: {
					if (_simulatorMenu)
					{
						menu.moveDown();
					}
					/*else if (_simulatorOptions)
					{
						options.moveDown();
					}*/
					else if (_simulatorPause) {
						pause.moveDown();
					}
					break;
				}
				case sf::Keyboard::Escape: {
					if (_simulatorLoop)
					{
						//_simulatorOptions = false;
						_simulatorPause = true;
						_simulatorLoop = true;
						_simulatorMenu = false;
						mouseDelta = 200;
						view.reset(sf::FloatRect(sf::Vector2f(width, height), sf::Vector2f(width * mouseDelta, height * mouseDelta)));
						view.setCenter(sf::Vector2f(-width, -height));
						simulator.setView(view);
					}
					else {
						//_simulatorOptions = false;
						_simulatorPause = false;
						_simulatorLoop = false;
						_simulatorMenu = true;
					}

					break;
				}
				case sf::Keyboard::Enter: {
					if (_simulatorMenu)
					{
						if (menu.selectedIndex() == 0)
						{
							//_simulatorOptions = false;
							_simulatorPause = false;
							_simulatorMenu = false;
							_simulatorLoop = true;
						}
						else if (menu.selectedIndex() == 1)
						{
							//_simulatorOptions = true;
							_simulatorMenu = false;
						}
						else if (menu.selectedIndex() == 2)
						{
							simulator.close();
						}
					}
					/*else if (_simulatorOptions)
					{
						if (options.selectedIndex() == 0)
						{
							///Resolution
						}
						else if (options.selectedIndex() == 1)
						{
							///Graphics
						}
						else if (options.selectedIndex() == 2)
						{
							_simulatorMenu = true;
							_simulatorOptions = false;
						}
					}*/
					else if (_simulatorLoop && _simulatorPause) {
						_simulatorLoop = false;
						if (pause.selectedIndex() == 0)
						{
							//_simulatorOptions = false;
							_simulatorPause = false;
							_simulatorMenu = false;
							_simulatorLoop = true;
						}
						else if (pause.selectedIndex() == 1)
						{
							//_simulatorOptions = true;
							_simulatorPause = false;
							_simulatorMenu = false;
							_simulatorLoop = false;
						}
						else if (pause.selectedIndex() == 2)
						{
							//_simulatorOptions = false;
							_simulatorPause = false;
							_simulatorMenu = true;
							_simulatorLoop = false;
							mouseDelta = 200;
							view.reset(sf::FloatRect(sf::Vector2f(width, height), sf::Vector2f(width * mouseDelta, height * mouseDelta)));
							view.setCenter(sf::Vector2f(-width, -height));
							simulator.setView(view);
						}
					}
					simulator.clear();
					break;
				}
				default:
					break;
				}
			}
		}

		if (_simulatorMenu) {
			menu.draw(simulator);
			menu.updateParallaxBackground(sf::Vector2f(sf::Mouse::getPosition().x * gainParallax,
				sf::Mouse::getPosition().y * gainParallax), gainParallax);
		}

		if (_simulatorLoop) {
			///ImGui interface
			ImGui::SFML::Update(simulator, simulator.getDeltaTime().getElapsedTime());

			ImGui::Begin("Solar System Configure");

			if (ImGui::ColorEdit3("Background color", color)) {
				bgColor.r = static_cast<sf::Uint8>(color[0] * 255.f);
				bgColor.g = static_cast<sf::Uint8>(color[1] * 255.f);
				bgColor.b = static_cast<sf::Uint8>(color[2] * 255.f);
			}

			if (ImGui::Checkbox("Backgroud Image", &backgroundImageState))
				backgroundSprite.setScale(ScaleX * mouseDelta / minMouseDelta, ScaleY * mouseDelta / minMouseDelta);


			ImGui::Checkbox("Background Solid Color", &backgroundSolidColorState);

			//if (!backgroundSolidColorState)
			//{
			//	bgColor = { 0, 0, 0 };
			//}

			if (ImGui::Checkbox("Set Default Raduis", &defaultRadiusState))
			{
				for (size_t count = 0; count < pla.getCountOfPlanets(); count++)
				{
					listPlanets[count]->setDefaultRadius();
				}
				radiusScaleUnits = 0;
			}

			ImGui::LabelText("", "Planets config:");

			ImGui::SliderFloat("Radius (units scale):", &radiusScaleUnits, 0, 10000);

			ImGui::LabelText("", "Generate new planet config:");

			ImGui::InputText("Mass: ", newMassBuffer, sizeof(newMassBuffer));
			ImGui::InputText("Radius: ", newRadiusBuffer, sizeof(newRadiusBuffer));

			ImGui::SliderFloat("Speed vector x0-> (units):", &speedScaleUnits.x, -100, 100);
			ImGui::SliderFloat("Speed vector y0-> (units):", &speedScaleUnits.y, -100, 100);

			newMass = atof(newMassBuffer);
			newRadius = atof(newRadiusBuffer);


			//ImGui::BeginGroup();
			for (size_t count = 0; count < packImagesPath.size(); count++)
			{
				ImGui::Image(spritePackImage[count], ImVec2(25, 25));

				if (ImGui::IsItemClicked())
				{
					packItem = count;
				}
			}
			//ImGui::EndGroup();

			ImGui::End();

			for (size_t count = 0; count < pla.getCountOfPlanets(); count++)
			{
				listPlanets[count]->addRadius(radiusScaleUnits);
			}

			///ImGui interface end

			//Clear background (solid color)
			if (backgroundSolidColorState)
			{
				simulator.clear(bgColor);
			}
			else
			{
				simulator.clear(sf::Color(0, 0, 0));
			}

			if (backgroundImageState)
			{
				simulator.draw(backgroundSprite);
			}

			if (!_simulatorPause)
			{
				pla.calculatePositions();
			}
			///Draw planets
			simulator.draw(pla.getSun());

			for (size_t count = 0; count < pla.getCountOfPlanets(); count++)
			{
				simulator.draw(pla.getItem(count));
			}

			ImGui::SFML::Render(simulator);

		}

		///Game options
		/*if (_simulatorOptions)
		{
			options.draw(simulator);
		}*/

		///Game pause
		if (_simulatorPause)
		{
			pause.draw(simulator);
		}

		simulator.display();
	}

	ImGui::SFML::Shutdown();

	return 0;
}
