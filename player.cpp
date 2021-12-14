#include <fstream>

#include <SFML/Graphics.hpp>

#include "Global.hpp"
#include "Player.hpp"

PlayerInfoBlock::PlayerInfoBlock(const int& health, const int& armour, const long long& coins, const long long& starShard, const unsigned long long& jobsInInt, const unsigned long long& skillsInInt, const unsigned long long& inventoryInInt,
	const std::array<unsigned int, G::PlayerInfo::Inventory::NUMBER_OF_ITEMS>& numberItemsInv)
	: health(health), armour(armour), coins(coins), starShard(starShard), jobsInInt(jobsInInt), skillsInInt(skillsInInt), inventoryInInt(inventoryInInt)
{
	for (size_t i = 0; i < G::PlayerInfo::Inventory::NUMBER_OF_ITEMS; ++i)
		this->numberItemsInv[i] = numberItemsInv[i];
}

namespace Loaders
{
	bool savePlayerData(PlayerInfoBlock& data, const std::string& saveFileName)
	{
		std::ofstream saveFile(G::RESOURCES_DIR + saveFileName, std::ios::binary | std::ios::out | std::ios::trunc);

		if (!saveFile.is_open())
		{
			G::errorLogger("Unable to open savefile for saving -  " + saveFileName);
			return false;
		}

		saveFile.write(reinterpret_cast<char*>(&data), sizeof(data));

		saveFile.close();

		return true;
	}

	bool loadPlayerData(PlayerInfoBlock& loadedData, const std::string& saveFileName)
	{
		std::ifstream saveFile(G::RESOURCES_DIR + saveFileName, std::ios::binary | std::ios::in);

		if (!saveFile.is_open())
		{
			G::errorLogger("Unable to open savefile for loading -  " + saveFileName);
			return false;
		}

		saveFile.read(reinterpret_cast<char*>(&loadedData), sizeof(loadedData));

		return true;
	}
}

Player::Player(const int& health, const int& armour, const long long& coins, const long long& starShard, const unsigned long long& jobsInInt, const unsigned long long& skillsInInt, const unsigned long long& inventoryInInt,
	const std::array<unsigned int, G::PlayerInfo::Inventory::NUMBER_OF_ITEMS>& numberItemsInv)
	: health(health), armour(armour), coins(coins), starShard(starShard), jobsInInt(jobsInInt), skillsInInt(skillsInInt), inventoryInInt(inventoryInInt), numberItemsInv(numberItemsInv) {}

void Player::rebuild(const PlayerInfoBlock& data)
{
	this->health = data.health;
	this->armour = data.armour;
	
	this->coins = data.coins;
	this->starShard = data.starShard;

	this->jobsInInt = data.jobsInInt;
	this->skillsInInt = data.skillsInInt;
	this->inventoryInInt = data.inventoryInInt;

	for (size_t i = 0; i < G::PlayerInfo::Inventory::NUMBER_OF_ITEMS; ++i)
		this->numberItemsInv[i] = data.numberItemsInv[i];
}

PlayerInfoBlock Player::getData()
{
	return PlayerInfoBlock(this->health, this->armour, this->coins, this->starShard, this->jobsInInt,
		this->skillsInInt, this->inventoryInInt, this->numberItemsInv);
}

