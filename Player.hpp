#pragma once

#include <string>
#include <unordered_map>
#include <array>

#include "Global.hpp"

class PlayerInfoBlock
{
public:
	PlayerInfoBlock(const int& health = 100, const int& armour = 0, const long long& coins = 0,
		const long long& starShard = 0, const unsigned long long& jobsInInt = 0b0, const unsigned long long& skillsInInt = 0b0, const unsigned long long& inventoryInInt = 0b0,
		const std::array<unsigned int, G::PlayerInfo::Inventory::NUMBER_OF_ITEMS>& numberItemsInv = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, });

	int health, armour;
	long long coins, starShard;
	unsigned long long jobsInInt, skillsInInt, inventoryInInt;
	unsigned int numberItemsInv[G::PlayerInfo::Inventory::NUMBER_OF_ITEMS];
};

namespace Loaders
{
	bool savePlayerData(PlayerInfoBlock& data, const std::string& saveFileName);

	bool loadPlayerData(PlayerInfoBlock& loadedData, const std::string& saveFileName);
}

class Player
{
public:
	Player(const int& health = 100, const int& armour = 0, const long long& coins = 0,
		const long long& starShard = 0, const unsigned long long& jobsInInt = 0b0, const unsigned long long& skillsInInt = 0b0, const unsigned long long& inventoryInInt = 0b0, 
		const std::array<unsigned int, G::PlayerInfo::Inventory::NUMBER_OF_ITEMS>& numberItemsInv = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,});

	void rebuild(const PlayerInfoBlock& data);
	PlayerInfoBlock getData();

private:
	int health, armour;
	long long coins, starShard;

	std::unordered_map<std::string, unsigned int> skills;
	std::unordered_map<std::string, unsigned int> inventory;
	unsigned long long jobsInInt;
	unsigned long long skillsInInt;
	unsigned long long inventoryInInt;
	std::array<unsigned int, G::PlayerInfo::Inventory::NUMBER_OF_ITEMS> numberItemsInv;
};