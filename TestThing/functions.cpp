#include <iostream>

#include "functions.h"
#include "Utils.h"

Player_getSpeed getSpeed;
//Player_getXuid getXuid;
Player_canDestroy canDestroy;
Actor_getNameTag getNameTag;
Actor_getRotation getRotation;

void* getFunctionAddress(std::string symbol)
{
	return Utils::offsetManagement::getHookPoint(Utils::offsetManagement::getSymbolOffset(symbol));
}

extern "C" __declspec(dllexport) void initFunctions() {
	getSpeed = (Player_getSpeed)getFunctionAddress("?getSpeed@Player@@UEBAMXZ");
	//getXuid = (Player_getXuid)Utils::offsetManagement::getHookPoint(Utils::offsetManagement::getSymbolOffset("?getXuid@Player@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ"));
	canDestroy = (Player_canDestroy)getFunctionAddress("?canDestroy@Player@@QEBA_NAEBVBlock@@@Z");
	getNameTag = (Actor_getNameTag)getFunctionAddress("?getNameTag@Actor@@UEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ");
	getRotation = (Actor_getRotation)getFunctionAddress("?getRotation@Actor@@QEBA?AVVec2@@XZ");
}

std::string getXuid(Player* pl) {
	std::string(Player :: * rv)() const;
	//*((void**)&rv) = dlsym("?getXuid@Player@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ");
	*((void**)&rv) = Utils::offsetManagement::getHookPoint(Utils::offsetManagement::getSymbolOffset("?getXuid@Player@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ"));
	std::cout << rv << "\n";
	return (pl->*rv)();
}