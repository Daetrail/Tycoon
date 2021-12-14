#include <string>
#include <SFML/Graphics.hpp>

#include "BaseMenu.hpp"
#include "Global.hpp"

BaseMenu::BaseMenu(const std::string& bgFile, std::shared_ptr<sf::Font> font)
    : bgFile(bgFile), bgTexture(new sf::Texture), font(font)
{
    if (!this->bgTexture.get()->loadFromFile(this->bgFile))
        G::errorLogger("Cannot open background file - " + this->bgFile);
    else
        this->bgSprite.setTexture(*this->bgTexture);
}

BaseMenu::BaseMenu(std::shared_ptr<sf::Texture> bgTexture, std::shared_ptr<sf::Font> font)
    : bgTexture(bgTexture), font(font)
{
    this->bgSprite.setTexture(*this->bgTexture.get());
}

std::shared_ptr<sf::Texture> BaseMenu::getTexture()
{
    return this->bgTexture;
}