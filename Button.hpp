#pragma once

#include <string>
#include <memory>

#include <SFML/Graphics.hpp>

#include "Global.hpp"

class Button
{
public:
	Button(std::shared_ptr<sf::Font> font, std::shared_ptr<sf::Texture> spriteSheetTexture, const std::string& label, const unsigned int& charSize, const sf::Vector2f& pos, const bool& isCentered, const sf::Color& defaultColour, const sf::Color& hoveredColour);

	bool isHovered(const sf::Vector2i& mousePos);
	bool isClicked(const sf::Vector2i& mousePos, sf::Event& event);

	void setButtonBgScale(const sf::Vector2f& scale);
	sf::Vector2f getPos();

	void update(const sf::Vector2i& mousePos);

	void draw(sf::RenderWindow& window);

private:
	sf::Text text;
	sf::Sprite buttonBgSprite;

	sf::Vector2f pos;

	sf::Color defaultColour;
	sf::Color hoveredColour;
};

