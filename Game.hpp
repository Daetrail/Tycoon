#pragma once

#include <string>
#include <memory>

#include <SFML/Graphics.hpp>

#include "Icon.hpp"
#include "BaseMenu.hpp"
#include "Player.hpp"
#include "Text.hpp"

class Game : BaseMenu
{
public:
	Game(std::shared_ptr<sf::Texture> bgTexture, std::shared_ptr<sf::Texture> spriteSheetTex, std::shared_ptr<sf::Font> font);

	void draw(sf::RenderWindow& window);

private:
	unsigned int spacer = 100;

	Icon coins;
	Text coinsAmount;
	Icon starShards;
};

