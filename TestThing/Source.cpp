#include "Utils.h"
#include "functions.h"
#include "Hooks.h"
#include "java.h"

#include <iostream>

extern "C" __declspec(dllexport) void init(std::string cachePath)
{
	std::cout << "[Spigot Loader] Initilizing..." << "\n";
	
	// Filess Utils::pdbSymbols::symbolMap
	Utils::pdbSymbols::pdbcacheToMap(Utils::fileIo::readFileAsString(cachePath));
	
	// Defines function links
	initFunctions();

	// Initiates Hooks
	initHooks();

	// Initiates the JVM and class loader
	initJava();

	std::cout << "[Spigot Loader] Intilized!!!" << "\n";
}

extern "C"
{
	__declspec(dllexport) float playerGetSpeed(void* param1)
	{
		return getSpeed(param1);
	}

	__declspec(dllexport) std::string playerGetXuid(Player* player)
	{
		return getXuid(player);
	}

	__declspec(dllexport) std::string actorGetNameTag(Actor* player)
	{
		return getNameTag(player);
	}

	__declspec(dllexport) void* actorGetRotation(void* player) 
	{
		return getRotation(player);
	}

	__declspec(dllexport) void testFunction(Player* player) 
	{
		std::cout << (__int64)player << "\n";
	}
}