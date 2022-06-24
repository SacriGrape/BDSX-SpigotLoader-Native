#include "iostream"
#include "DLL/MinHook.h"

#include "Hooks.h"

Actor_getNameTag oGetNameTag = nullptr;
Player_canDestroy oCanDestroy = nullptr;

void initHooks()
{
	MH_Initialize();

	MH_EnableHook(MH_ALL_HOOKS);
}