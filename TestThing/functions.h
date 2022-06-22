#pragma once
#include <string>

class Player {};
class Actor {};
class Block {};

typedef float(*Player_getSpeed)(void*);
typedef std::string(*Player_getXuid)(std::string*, void*);
typedef std::string&(*Actor_getNameTag)(Actor*);
typedef bool(*Player_canDestroy)(Player*, Block*);
typedef void* (*Actor_getRotation)(void*);

extern "C" __declspec(dllexport) void initFunctions();

extern Player_getSpeed getSpeed;
//extern Player_getXuid getXuid;
extern Player_canDestroy canDestroy;
extern Actor_getNameTag getNameTag;
extern Actor_getRotation getRotation;

std::string getXuid(Player* pl);