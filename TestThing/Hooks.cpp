#include "iostream"
#include "DLL/MinHook.h"

#include "Hooks.h"

Actor_getNameTag oGetNameTag = nullptr;

bool returnsHello(Actor* actor, Block* block) {
	std::cout << (__int64)actor << "\n";
	
	return true;
}


void initHooks()
{
	MH_Initialize();

	MH_CreateHook(canDestroy, returnsHello, reinterpret_cast<void**>(oGetNameTag));

	MH_EnableHook(MH_ALL_HOOKS);
}