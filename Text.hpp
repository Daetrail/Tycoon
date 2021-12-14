#pragma once

#include <string>
#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

class Text
{
public:
	Text(std::shared_ptr<sf::Font> font, std::shared_ptr<sf::Texture> spriteSheetTex, const std::string& label, const sf::Vector2f& pos, const unsigned int& charSize, const sf::Color& fillColour, const bool& isCentered);
	Text(std::shared_ptr<sf::Font> font, std::shared_ptr<sf::Texture> spriteSheetTex, const std::vector<std::string> labels, const sf::Vector2f& pos, const unsigned int& charSize, const sf::Color& fillColour, const unsigned int& spacing);

	void setTextBoxScale(const sf::Vector2f& scale);
	void moveTextBox(const float& x, const float& y);
	
	void setString(const std::string& string);

	sf::Vector2f getPos();
	sf::Vector2f getTopLeftPos();

	void draw(sf::RenderWindow& window);

private:
	bool isCentered = false;
	bool isMultiLine = false;

	sf::Text line;
	std::vector<sf::Text> lines;

	sf::Vector2f multiLinePos;
	sf::Vector2f centeredMultiLinePos;

	sf::Sprite textBox;
};

