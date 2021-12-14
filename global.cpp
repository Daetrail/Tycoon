#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <fstream>
#include <ctime>
#include <chrono>
#include <iostream>
#include <iomanip>

#include "Global.hpp"

namespace G
{
	const std::vector<std::string> G::ABOUT_STRING = {
		"test test yo mama test test test",
		"yoyoyoyoyoyoyoyoyoyoyoyoyoyoyooyoyyo",
		"yoyoyoyoyfjsigisbigigiurhsiufhsiurhfi",
		"uidshiufhdsiubfidsbfidsbfidsbifdbs",
		"bdjsfishiufhsiuhfdshfshfdhs"
	};

	void errorLogger(const std::string& errorMsg)
	{
		std::ofstream logFile(G::RESOURCES_DIR + G::LOG_FILE, std::ios::out | std::ios::app);

		if (!logFile.is_open())
		{
			std::cerr << "Unable to write error into logfile: " << G::LOG_FILE << std::endl;
			std::cerr << "Error: " << errorMsg << std::endl;
			std::cerr << "Please create a text file with the name: " << G::LOG_FILE << std::endl;
			return;
		}

		auto start = std::chrono::system_clock::now();
		std::time_t time = std::chrono::system_clock::to_time_t(start);
		std::tm* ptm = std::localtime(&time);

		logFile << "Time of Error: " << std::put_time(ptm, "%c") << std::endl;
		logFile << "Error: " << errorMsg << std::endl << std::endl;
	}

	Game::GameState Game::curGameState = Game::GameState::mainMenu;

	namespace SpriteSheet
	{
		const sf::IntRect TextureData::buttonBox = { 0, 0, 64, 32 };
		const sf::IntRect TextureData::coin = { 64, 0, 32, 32 };
		const sf::IntRect TextureData::starShard = { 96, 0, 32, 32 };
		const sf::IntRect TextureData::fishingRod = { 128, 0, 32, 32 };
		const sf::IntRect TextureData::shovel = { 160, 0, 32, 32 };
	}
}