#include <memory>

#include <SFML/Graphics.hpp>

#include "Global.hpp"
#include "MainMenu.hpp"
#include "Game.hpp"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = G::ANTIALIASING_LEVEL;
	sf::RenderWindow window(sf::VideoMode(G::WINDOW_WIDTH, G::WINDOW_HEIGHT), G::WINDOW_TITLE, sf::Style::Titlebar | sf::Style::Close, settings);
	window.setFramerateLimit(G::FPS_LIMIT);

	auto mainFont = std::make_shared<sf::Font>();
	if (!mainFont.get()->loadFromFile(G::RESOURCES_DIR + G::FONT_FILE))
		G::errorLogger("Cannot open font file - " + G::RESOURCES_DIR + G::FONT_FILE);

	auto spriteSheetTex = std::make_shared<sf::Texture>();
	if (!spriteSheetTex.get()->loadFromFile(G::RESOURCES_DIR + G::SPRITESHEET_FILE))
		G::errorLogger("Cannot open spritesheet file - " + G::RESOURCES_DIR + G::SPRITESHEET_FILE);

	MainMenu mainMenu(G::RESOURCES_DIR + G::BG_FILE, mainFont, spriteSheetTex);
	Game game(mainMenu.getTexture(), spriteSheetTex, mainFont);

	sf::Vector2i mousePos;

	while (window.isOpen())
	{
		mousePos = sf::Mouse::getPosition(window);

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
					break;
			}

			switch (G::Game::curGameState)
			{
				using namespace G::Game;
			case GameState::mainMenu:
				mainMenu.manageMouseClicks(mousePos, event);
				break;
			case GameState::aboutMenu:
				break;
			case GameState::game:
				break;
			}
		}

		switch (G::Game::curGameState)
		{
			using namespace G::Game;
		case GameState::mainMenu:
			mainMenu.update(mousePos);
			break;
		case GameState::aboutMenu:
			break;
		case GameState::game:
			break;
		}

		window.clear(sf::Color::Black);

		switch (G::Game::curGameState)
		{
			using namespace G::Game;
		case GameState::mainMenu:
			mainMenu.draw(window);
			break;
		case GameState::aboutMenu:
			break;
		case GameState::game:
			game.draw(window);
			break;
		}

		window.display();
	}

}