#include <windows.h>
#include <iostream>

#include "Utils.h"

namespace Utils
{
	namespace fileIo
	{
		std::string readFileAsString(std::string path) {
			// Grabbing file stream from path
			std::ifstream file(path);

			// Looping over file as chars, pushing them into a string
			std::string fileString((std::istreambuf_iterator<char>(file)),
				std::istreambuf_iterator<char>());

			return fileString;
		}
	}

	namespace stringOperations
	{
		std::vector<std::string> splitString(std::string string, std::string delimiter)
		{

			std::vector<std::string> sections;
			int pos = 0;
			while ((pos = string.find(delimiter)) != std::string::npos) {
				std::string matchedSection = string.substr(0, pos);
				string.erase(0, pos + 1);
				sections.push_back(matchedSection);
			}

			std::string matchedSection = string.substr(0, pos);
			sections.push_back(matchedSection);

			return sections;
		}
	}

	namespace pdbSymbols
	{
		std::map<std::string, int> symbolMap;

		void pdbcacheToMap(std::string pdbcache) {
			std::vector<std::string> lines = Utils::stringOperations::splitString(pdbcache, "\n");
			for (std::string line : lines)
			{
				std::vector<std::string> symbolInfo = Utils::stringOperations::splitString(line, "|");
				if (symbolInfo[0] == "v")
				{
					Utils::pdbSymbols::symbolMap[symbolInfo[1]] = std::stoi(symbolInfo[2], nullptr, 16);
				}
				else if (symbolInfo.size() != 1) 
				{
					Utils::pdbSymbols::symbolMap[symbolInfo[0]] = std::stoi(symbolInfo[1], nullptr, 16);
				}
			}
		};
	}

	namespace offsetManagement
	{
		void* getHookPoint(int offset)
		{
			uintptr_t base = reinterpret_cast<uintptr_t>(GetModuleHandle(nullptr));
			return reinterpret_cast<void*>(base + offset);
		}	

		int getSymbolOffset(std::string symbol)
		{
			return Utils::pdbSymbols::symbolMap[symbol];
		}
	}
}