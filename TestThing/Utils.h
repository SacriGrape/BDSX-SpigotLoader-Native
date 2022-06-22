#pragma once

#include <string>
#include <fstream>
#include <map>
#include <vector>

namespace Utils
{
	namespace fileIo
	{
		std::string readFileAsString(std::string path);
	}

	namespace stringOperations
	{
		std::vector<std::string> splitString(std::string string, std::string delimiter);
	}

	namespace pdbSymbols
	{
		extern std::map<std::string, int> symbolMap;
		void pdbcacheToMap(std::string pdbcache);
	}

	namespace offsetManagement
	{
		void* getHookPoint(int offset);
		int getSymbolOffset(std::string symbol);
	}
};