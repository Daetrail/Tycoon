#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

class Icon
{
public:
	Icon(std::shared_ptr<sf::Texture> spriteSheetTex, const sf::IntRect& iconRect, const sf::Vector2f& pos);

	void setItemScale(const float& x, const float& y);

	sf::Vector2f getPos();
	sf::Vector2f getTopLeftPos();

	void draw(sf::RenderWindow& window);

private:
	sf::Sprite iconBg;
	sf::Sprite iconItem;
};

