#pragma once

#include <memory>
#include <vector>
#include <string>

#include <SFML/Graphics.hpp>

#include "BaseMenu.hpp"
#include "Button.hpp"
#include "Text.hpp"

class MainMenu : public BaseMenu
{
public:
	MainMenu(const std::string& bgFile, std::shared_ptr<sf::Font> font, std::shared_ptr<sf::Texture> spriteSheetTex);

	void manageMouseClicks(sf::Vector2i& mousePos, sf::Event& event);

	void update(sf::Vector2i& mousePos);

	void draw(sf::RenderWindow& window);

private:
	unsigned int buttonSpacer = 150;

	Text title;

	Button playButton;
	Button aboutButton;
	Button exitButton;
};

