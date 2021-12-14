#include "Game.hpp"
#include "Global.hpp"

Game::Game(std::shared_ptr<sf::Texture> bgTexture, std::shared_ptr<sf::Texture> spriteSheetTex, std::shared_ptr<sf::Font> font)
	: BaseMenu(bgTexture, font),
	coins(spriteSheetTex, G::SpriteSheet::TextureData::coin, sf::Vector2f(75, 75)),
	coinsAmount(font, spriteSheetTex, "0", sf::Vector2f(this->coins.getTopLeftPos().x + this->spacer, this->coins.getTopLeftPos().y), 70, sf::Color::Black, false),
	starShards(spriteSheetTex, G::SpriteSheet::TextureData::starShard, sf::Vector2f(this->coins.getPos().x, this->coins.getPos().y + this->spacer))
{
	this->coins.setItemScale(2.f, 2.f);
	this->starShards.setItemScale(2.f, 2.f);
}

void Game::draw(sf::RenderWindow& window)
{
	window.draw(this->bgSprite);
	this->coins.draw(window);
	this->coinsAmount.draw(window);
	this->starShards.draw(window);
}
