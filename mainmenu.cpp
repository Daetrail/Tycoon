#include "MainMenu.hpp"
#include "Global.hpp"

MainMenu::MainMenu(const std::string& bgFile, std::shared_ptr<sf::Font> font, std::shared_ptr<sf::Texture> spriteSheetTex)
	: BaseMenu(bgFile, font), 
	title(this->font, spriteSheetTex, G::WINDOW_TITLE, sf::Vector2f(G::WINDOW_WIDTH / 2, 100), 75, sf::Color::Black, true),
	playButton(this->font, spriteSheetTex, "Play", 70, sf::Vector2f(this->title.getPos().x, this->title.getPos().y + this->buttonSpacer), true, sf::Color::Black, sf::Color::Blue),
	aboutButton(this->font, spriteSheetTex, "About", 70, sf::Vector2f(this->title.getPos().x, this->playButton.getPos().y + buttonSpacer), true, sf::Color::Black, sf::Color::Blue),
	exitButton(this->font, spriteSheetTex, "Exit", 70, sf::Vector2f(this->title.getPos().x, this->aboutButton.getPos().y + buttonSpacer), true, sf::Color::Black, sf::Color::Red) {}

void MainMenu::manageMouseClicks(sf::Vector2i& mousePos, sf::Event& event)
{
	if (this->playButton.isClicked(mousePos, event))
	{
		G::Game::curGameState = G::Game::GameState::game;
	}

	if (this->exitButton.isClicked(mousePos, event))
	{
		std::exit(EXIT_SUCCESS);
	}
}

void MainMenu::update(sf::Vector2i& mousePos)
{
	this->playButton.update(mousePos);
	this->aboutButton.update(mousePos);
	this->exitButton.update(mousePos);

}

void MainMenu::draw(sf::RenderWindow& window)
{
	window.draw(bgSprite);
	this->title.draw(window);
	this->playButton.draw(window);
	this->aboutButton.draw(window);
	this->exitButton.draw(window);
}

