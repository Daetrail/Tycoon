#pragma once

#include <memory>
#include <string>

#include <SFML/Graphics.hpp>

class BaseMenu
{
public:
    BaseMenu(const std::string& bgFile, std::shared_ptr<sf::Font> font);
    BaseMenu(std::shared_ptr<sf::Texture> bgTexture, std::shared_ptr<sf::Font> font);

    std::shared_ptr<sf::Texture> getTexture();

protected:
    std::string bgFile;
    std::shared_ptr<sf::Texture> bgTexture;
    sf::Sprite bgSprite;

    std::shared_ptr<sf::Font> font;
};