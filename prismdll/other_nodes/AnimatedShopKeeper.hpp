#pragma once

#include "../pch.h"
#include <gd.h>

namespace prismdll
{
	class AnimatedShopKeeper : public cocos2d::CCNode
	{
	protected:

	protected:
		static inline bool(__thiscall* init)(AnimatedShopKeeper*, gd::ShopType*);
		static bool __fastcall initHook(AnimatedShopKeeper* self, gd::ShopType shopType)
		{

		}

	public:
		static void loadHook()
		{
			MH_CreateHook(
				(PVOID)(gd::base + 0x14c5b0),
				(LPVOID)AnimatedShopKeeper::initHook,
				(LPVOID*)&AnimatedShopKeeper::init
			);
		}
	};
}
