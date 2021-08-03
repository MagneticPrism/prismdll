#pragma once

#include "../pch.h"
#include <gd.h>

using namespace cocos2d;

class GJItemIcon : public CCSprite
{
protected:
	static inline bool(__thiscall* init)(GJItemIcon*, uintptr_t, gd::UnlockType, int, ccColor3B, ccColor3B, bool, bool, bool, ccColor3B);
	static bool __fastcall initHook(GJItemIcon* self, uintptr_t edx, gd::UnlockType unlockType, int iconID, ccColor3B col1, ccColor3B col2, bool un0, bool un1, bool un2, ccColor3B col3)
	{
		if (unlockType == gd::kUnlockTypeCube && iconID > 142)
		{
			if (!init(self, edx, unlockType, iconID, col1, col2, un0, un1, un2, col3))
				return false;

			init(self, edx, unlockType, iconID, col1, col2, un0, un1, un2, col3);

			return true;
		}
	}
public:
	static void loadHook()
	{
		MH_CreateHook(
			(PVOID)(gd::base + 0x12ccf0),
			(LPVOID)GJItemIcon::initHook,
			(LPVOID*)&GJItemIcon::init
		);
	}
};
