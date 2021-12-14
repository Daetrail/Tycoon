#include "Text.hpp"
#include "Global.hpp"

Text::Text(std::shared_ptr<sf::Font> font, std::shared_ptr<sf::Texture> spriteSheetTex, const std::string& label, const sf::Vector2f& pos, const unsigned int& charSize, const sf::Color& fillColour, const bool& isCentered)
	: isCentered(isCentered)
{
	this->lines.~vector();

	this->textBox.setTexture(*spriteSheetTex.get());
	this->textBox.setTextureRect(G::SpriteSheet::TextureData::buttonBox);

	this->line.setFont(*font.get());
	this->line.setString(label);
	this->line.setCharacterSize(charSize);
	this->line.setFillColor(fillColour);

	if (this->isCentered)
	{
		this->line.setOrigin(this->line.getGlobalBounds().width / 2 + this->line.getGlobalBounds().left, this->line.getGlobalBounds().height / 2 + this->line.getGlobalBounds().top);
	}
	
	this->textBox.setOrigin(this->textBox.getGlobalBounds().width / 2, this->textBox.getGlobalBounds().height / 2);

	this->line.setPosition(pos);

	float scaleX = (this->line.getGlobalBounds().width * 1.5 + this->line.getLocalBounds().left) / static_cast<float>(G::SpriteSheet::TextureData::buttonBox.width);
	float scaleY = (this->line.getGlobalBounds().height * 1.5 + this->line.getLocalBounds().top) / static_cast<float>(G::SpriteSheet::TextureData::buttonBox.height);
	this->textBox.setScale(scaleX, scaleY);

	if (this->isCentered)
		this->textBox.setPosition(this->line.getPosition());
	else
		this->textBox.setPosition(this->line.getPosition().x + this->line.getLocalBounds().width / 2 + this->line.getLocalBounds().left, this->line.getPosition().y + this->line.getLocalBounds().height / 2 + this->line.getLocalBounds().top);
}

Text::Text(std::shared_ptr<sf::Font> font, std::shared_ptr<sf::Texture> spriteSheetTex, const std::vector<std::string> labels, const sf::Vector2f& pos, const unsigned int& charSize, const sf::Color& fillColour, const unsigned int& spacing)
{
	this->isMultiLine = true;

	this->textBox.setTexture(*spriteSheetTex.get());
	this->textBox.setTextureRect(G::SpriteSheet::TextureData::buttonBox);

	sf::Vector2f changedPos = pos;
	for (size_t i = 0; i < labels.size(); ++i)
	{
		sf::Text text(labels[i], *font.get(), charSize);

		text.setFillColor(fillColour);
		text.setPosition(changedPos);

		this->lines.push_back(text);	

		changedPos = { changedPos.x, changedPos.y + spacing };
	}

	this->textBox.setPosition(this->lines[0].getPosition().x - this->lines[0].getLocalBounds().left, this->lines[0].getPosition().y - this->lines[0].getLocalBounds().top);
}

void Text::setTextBoxScale(const sf::Vector2f& scale)
{
	this->textBox.setScale(scale);
}

void Text::moveTextBox(const float& x, const float& y)
{
	this->textBox.move(x, y);
}

sf::Vector2f Text::getPos()
{
	if (isMultiLine)
	{
		return this->lines[0].getPosition();
	}
	return line.getPosition();
}

sf::Vector2f Text::getTopLeftPos()
{	
	if (!this->isCentered)
		return sf::Vector2f(this->line.getPosition().x - this->line.getGlobalBounds().width / 2 - this->line.getLocalBounds().left, this->line.getPosition().y - this->line.getGlobalBounds().height / 2 - this->line.getLocalBounds().top);
	return this->line.getPosition();
}

void Text::setString(const std::string& string)
{
	this->line.setString(string);

	float scaleX = (this->line.getGlobalBounds().width * 1.5 + this->line.getLocalBounds().left) / static_cast<float>(G::SpriteSheet::TextureData::buttonBox.width);
	float scaleY = (this->line.getGlobalBounds().height * 1.5 + this->line.getLocalBounds().top) / static_cast<float>(G::SpriteSheet::TextureData::buttonBox.height);

	this->textBox.setScale(scaleX, scaleY);

	if (this->isCentered)
		this->textBox.setPosition(this->line.getPosition());
	else
		this->textBox.setPosition(this->line.getPosition().x + this->line.getGlobalBounds().width / 2 + this->line.getLocalBounds().left, this->line.getPosition().y + this->line.getGlobalBounds().height / 2 + this->line.getLocalBounds().top);
}

void Text::draw(sf::RenderWindow& window)
{
	window.draw(this->textBox);
	if (isMultiLine)
	{
		for (auto line : lines)
		{
			window.draw(line);
		}
	}
	else
	{
		window.draw(this->line);
	}
}
