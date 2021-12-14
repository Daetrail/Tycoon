#include "Button.hpp"
#include "Global.hpp"

#include <iostream>

Button::Button(std::shared_ptr<sf::Font> font, std::shared_ptr<sf::Texture> spriteSheetTexture, const std::string& label, const unsigned int& charSize, const sf::Vector2f& pos, const bool& isCentered, const sf::Color& defaultColour, const sf::Color& hoveredColour)
	: pos(pos), defaultColour(defaultColour), hoveredColour(hoveredColour)
{
	this->buttonBgSprite.setTexture(*spriteSheetTexture.get());
	this->buttonBgSprite.setTextureRect(G::SpriteSheet::TextureData::buttonBox);

	this->text.setFont(*font.get());
	this->text.setCharacterSize(charSize);
	this->text.setString(label);
	this->text.setFillColor(this->defaultColour);
	
	if (isCentered)
	{
		this->text.setOrigin(this->text.getGlobalBounds().width / 2 + this->text.getGlobalBounds().left,
			this->text.getGlobalBounds().height / 2 + this->text.getGlobalBounds().top);
		this->buttonBgSprite.setOrigin(this->buttonBgSprite.getGlobalBounds().width / 2, this->buttonBgSprite.getGlobalBounds().height / 2);
	}

	this->text.setPosition(pos);

	float scaleX = (this->text.getGlobalBounds().width * 1.5 + this->text.getLocalBounds().left) / static_cast<float>(G::SpriteSheet::TextureData::buttonBox.width);
	float scaleY = (this->text.getGlobalBounds().height * 1.5 + this->text.getLocalBounds().top) / static_cast<float>(G::SpriteSheet::TextureData::buttonBox.height);

	this->buttonBgSprite.setPosition(this->text.getPosition());
	this->buttonBgSprite.setScale(scaleX, scaleY);
}

bool Button::isHovered(const sf::Vector2i& mousePos)
{
	sf::FloatRect buttonBoundBox = this->buttonBgSprite.getGlobalBounds();

	if (buttonBoundBox.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		this->text.setFillColor(this->hoveredColour);
		return true;
	}

	this->text.setFillColor(this->defaultColour);
	return false;
}

bool Button::isClicked(const sf::Vector2i& mousePos, sf::Event& event)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (this->isHovered(mousePos))
		{
			if (event.mouseButton.button == sf::Mouse::Left)
				return true;
			else
				return false;
		}
		return false;
	}
	return false;
}

void Button::setButtonBgScale(const sf::Vector2f& scale)
{
	this->buttonBgSprite.setScale(scale);
}

sf::Vector2f Button::getPos()
{
	return this->text.getPosition();
}

void Button::update(const sf::Vector2i& mousePos)
{
	this->isHovered(mousePos);
}

void Button::draw(sf::RenderWindow& window)
{
	window.draw(this->buttonBgSprite);
	window.draw(this->text);
}

