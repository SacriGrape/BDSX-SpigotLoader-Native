#include "iostream"
#include "DLL/MinHook.h"

#include "Hooks.h"

Actor_getNameTag oGetNameTag = nullptr;
Player_canDestroy oCanDestroy = nullptr;

std::string& getNameHook(Actor* actor) {
	std::string name = oGetNameTag(actor);
	std::cout << name << "\n";
	name = "Hello";
	return name;
}


void initHooks()
{
	MH_Initialize();

	MH_CreateHook(getNameTag, getNameHook, reinterpret_cast<LPVOID*>(&oGetNameTag));

	MH_EnableHook(MH_ALL_HOOKS);
}