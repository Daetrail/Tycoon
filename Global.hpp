#pragma once

#include <SFML/Graphics.hpp>

#include <string>
#include <fstream>
#include <ctime>
#include <chrono>
#include <array>
#include <vector>

namespace G
{
	constexpr unsigned int WINDOW_WIDTH = 1200;
	constexpr unsigned int WINDOW_HEIGHT = 900;
	constexpr char WINDOW_TITLE[] = "Money Tycoon";
	constexpr unsigned short FPS_LIMIT = 60;
	constexpr unsigned short ANTIALIASING_LEVEL = 8;
	
	const std::string RESOURCES_DIR = "resources/";

	constexpr char LOG_FILE[] = "log.txt";

	const std::string BG_FILE = "seaside.png";
	const std::string FONT_FILE = "rainyhearts.ttf";

	constexpr char SPRITESHEET_FILE[] = "spritesheet.png";

	extern const std::vector<std::string> ABOUT_STRING;

	void errorLogger(const std::string& errorMsg);

	namespace Game
	{
		enum class GameState : unsigned int
		{
			mainMenu,
			aboutMenu,
			game
		};
		extern GameState curGameState;
	}

	namespace PlayerInfo
	{
		/*
			-- QUICK OVERVIEW --
			General Skills:
			Novice Beggar, True Beggar, Advanced Beggar, Master Beggar, Negotiator
			Novice Hunter, True Hunter, Advanced Hunter, Master Hunter, Predator
			Novice Fisherman, True Fisherman, Advanced Fisherman, Master Fisherman, Megalodon
			Novice Excavator, True Excavator, Advanced Excavator, Master Excavator, Topman
			Novice Seeker, True Seeker, Advanced Seeker, Master Seeker, Archaeologist,
			Novice Memer, True Memer, Advanced Memer, Master Memer, Dank Memer

			Jobs:
			Kitty Rescuer
			Maths Teacher
			Jet Pilot

			Inventory:
			Hunting Rifle: 10000
			Fishing Rod: 12000
			Shovel: 25000
			Laptop: 15000
			...
			Engagement Ring: 550000
			Secret Key: Easter egg, allows for admin access, achieved at attainment of Fox Trophy
			Fox Trophy: Achieved at end game
				Conditions: 1,000,000,000 coins, 1,000,000 star shards, max skills

			/ (EXCEPT BEGGAR AND MEMER) /
			/ No rank:                  /
			/ 1-3 = 97%                 /
			/ 4-5 = 2%                  /
			/ 6-7 = 1%                  /

			Novice:
				Memer and Beggar: 10% more, +5% each rank, Dank Memer/Negotiator: 50% increase (total)
				The Rest: 1-3 = 94%, 4-5 = 4%, 6-7 = 2%
			True:
				The Rest: 1-3 = 87%, 4-5 = 8%, 6-7 = 5%
			Advanced:
				The Rest: 1-3 = 80%, 4-5 = 12%, 6-7 = 8%
			Master:
				The Rest: 1-3 = 73%, 4-5 = 16%, 6-7 = 11%
			Final:
				The Rest: 1-3 = 65%, 4-5 = 20%, 6-7 = 15%

			ONLY BEGGAR AND MEMER STACKS UP, NOTHING ELSE!
		*/
		constexpr unsigned long long bitMask = 0b1;
		namespace Skills
		{
			enum skill : unsigned long long
			{
				noviceBeggar = (bitMask << 0), trueBeggar = (bitMask << 1), advancedBeggar = (bitMask << 2), masterBeggar = (bitMask << 3), Negotiator = (bitMask << 4),
				noviceHunter = (bitMask << 5), trueHunter = (bitMask << 6), advancedHunter = (bitMask << 7), masterHunter = (bitMask << 8), Predator = (bitMask << 9),
				noviceFisherman = (bitMask << 10), trueFisherman = (bitMask << 11), advancedFisherman = (bitMask << 12), masterFisherman = (bitMask << 13), Megalodon = (bitMask << 14),
				noviceExcavator = (bitMask << 15), trueExcavator = (bitMask << 16), advancedExcavator = (bitMask << 17), masterExcavator = (bitMask << 18), Topman = (bitMask << 19),
				noviceSeeker = (bitMask << 20), trueSeeker = (bitMask << 21), advancedSeeker = (bitMask << 22), masterSeeker = (bitMask << 23), Archaeologist = (bitMask << 24),
				noviceMemer = (bitMask << 25), trueMemer = (bitMask << 26), advancedMemer = (bitMask << 27), masterMemer = (bitMask << 28), dankMemer = (bitMask << 28)
			};
		}
		namespace Jobs
		{
			enum job : unsigned long long
			{
				kittyRescuer = (bitMask << 0), mathsTeacher = (bitMask << 1), jetPilot = (bitMask << 2)
			};
		}
		namespace Inventory
		{
			constexpr size_t NUMBER_OF_ITEMS = 36;

			enum class InventoryItems : unsigned long long
			{
				// Equipment
				huntingRifle = (bitMask << 0), fishingRod = (bitMask << 1), shovel = (bitMask << 2), metalDetector = (bitMask << 3), laptop = (bitMask << 4),
				// Hunting
				squirrel = (bitMask << 5), deer = (bitMask << 6), moose = (bitMask << 7), duck = (bitMask << 8), bear = (bitMask << 9), dinosaur = (bitMask << 10), dragon = (bitMask << 11),
				// Fishing
				cod = (bitMask << 12), salmon = (bitMask << 13), clownFish = (bitMask << 14), piranha = (bitMask << 15), greatWhiteShark = (bitMask << 16), blueWhale = (bitMask << 17), megalodon = (bitMask << 18),
				// Digging
				rock = (bitMask << 19), crystal = (bitMask << 20), silver = (bitMask << 21), gold = (bitMask << 22), ruby = (bitMask << 23), diamond = (bitMask << 24), ademantite = (bitMask << 25),
				// Metal Detector
				toyCar = (bitMask << 26), brokenSpeaker = (bitMask << 27), goldCoin = (bitMask << 28), silverRing = (bitMask << 29), antiqueWatch = (bitMask << 30), romanCoin = (bitMask << 31), sunMetal = (bitMask << 32),
				// Miscellaneous
				engagementRing = (bitMask << 33), secretKey = (bitMask << 34), foxTrophy = (bitMask << 35)
			};

			enum class InventoryIndex
			{
				huntingRifle, fishingRod, shovel, metalDetector, laptop,
				squirrel, deer, moose, duck, bear, dinosaur, dragon,
				cod, salmon, clownFish, piranha, greatWhiteShark, blueWhale, megalodon,
				rock, crystal, silver, gold, ruby, diamond, ademantite,
				toyCar, brokenSpeaker, goldCoin, silverRing, antiqueWatch, romanCoin, sunMetal,
				engagementRing, secretKey, foxTrophy
			};
		}
	}

	namespace SpriteSheet
	{
		struct TextureData
		{
			static const sf::IntRect buttonBox;
			static const sf::IntRect coin;
			static const sf::IntRect starShard;
			static const sf::IntRect huntingRifle;
			static const sf::IntRect fishingRod;
			static const sf::IntRect shovel;
		};
	}

}
