#include "Icon.hpp"
#include "Global.hpp"

Icon::Icon(std::shared_ptr<sf::Texture> spriteSheetTex, const sf::IntRect& iconRect, const sf::Vector2f& pos)
{
	this->iconBg.setTexture(*spriteSheetTex.get());
	this->iconBg.setTextureRect(G::SpriteSheet::TextureData::buttonBox);

	this->iconItem.setTexture(*spriteSheetTex.get());
	this->iconItem.setTextureRect(iconRect);

	this->iconBg.setOrigin(this->iconBg.getGlobalBounds().width / 2, this->iconBg.getGlobalBounds().height / 2);
	this->iconItem.setOrigin(this->iconItem.getGlobalBounds().width / 2, this->iconItem.getGlobalBounds().height / 2);

	float scaleX = (this->iconItem.getGlobalBounds().width * 1.5 + this->iconItem.getLocalBounds().left) / static_cast<float>(G::SpriteSheet::TextureData::buttonBox.width);
	float scaleY = (this->iconItem.getGlobalBounds().height * 1.5 + this->iconItem.getLocalBounds().top) / static_cast<float>(G::SpriteSheet::TextureData::buttonBox.height);

	this->iconBg.setScale(scaleX, scaleY);

	this->iconBg.setPosition(pos);
	this->iconItem.setPosition(pos);
}

void Icon::setItemScale(const float& x, const float& y)
{
	this->iconItem.setScale(x, y);

	float scaleX = (this->iconItem.getGlobalBounds().width * 1.5 + this->iconItem.getLocalBounds().left) / static_cast<float>(G::SpriteSheet::TextureData::buttonBox.width);
	float scaleY = (this->iconItem.getGlobalBounds().height * 1.5 + this->iconItem.getLocalBounds().top) / static_cast<float>(G::SpriteSheet::TextureData::buttonBox.height);

	this->iconBg.setScale(scaleX, scaleY);
	this->iconBg.setPosition(this->iconItem.getPosition());
}

sf::Vector2f Icon::getPos()
{
	return this->iconItem.getPosition();
}

sf::Vector2f Icon::getTopLeftPos()
{
	return sf::Vector2f(this->iconBg.getPosition().x - this->iconBg.getGlobalBounds().width / 2 - this->iconBg.getLocalBounds().left, this->iconBg.getPosition().y - this->iconBg.getGlobalBounds().height / 2 + this->iconBg.getLocalBounds().top);
}

void Icon::draw(sf::RenderWindow& window)
{
	window.draw(this->iconBg);
	window.draw(this->iconItem);
}
