#pragma once

#include "../pch.h"

namespace prismdll
{
	class AnimatedShopKeeper : public cocos2d::CCNode
	{
	protected:

	protected:
		static inline bool(__thiscall* init)(AnimatedShopKeeper*, gd::ShopType*);
		static bool __fastcall initHook(AnimatedShopKeeper* self, gd::ShopType shopType)
		{
			cocos2d::CCNode* pCVar1;
			char cVar2;
			const char* pcVar3;
			int iVar4;
			
			if (shopType == gd::kShopTypeSecret)
			{
				pcVar3 = "GJShopKeeper2";
			}
			else
			{
				if (shopType == gd::kShopTypeCommunity)
				{
					pcVar3 = "GJShopKeeper3";
				}
				else
				{
					if (shopType == gd::kShopTypeTest)
					{
						pcVar3 = "GJShopKeeper";
					}
					else
					{
						pcVar3 = "GJShopKeeper";
					}
				}
			}

			AnimatedShopKeeper::weirdFunc(self, pcVar3);

			if (cVar2 == '\0')
			{
				return false;
			}

			iVar4 = rand();

			*(int*)(self + 0x248) = (int)(((float)iVar4 / 32767.0) * 5.0 + 10.0);
			iVar4 = rand();

			*(int*)(self + 0x244) = (int)(((float)iVar4 / 32767.0) * 2.0 + 1.0);

			iVar4 = *(int*)(self + 0x214);

			AnimatedShopKeeper::weirdFunc2(self, (int**)"not_used", (int*)0x8);

			pCVar1 = *(CCNode**)(*(int*)(iVar4 + 0xec) + 0x220);

			if (pCVar1 != (CCNode*)0x0) {
				pCVar1->stopAllActions();
			}

			pCVar1 = *(CCNode**)(*(int*)(iVar4 + 0xec) + 0x21c);

			if (pCVar1 != (CCNode*)0x0) {
				pCVar1->stopAllActions();
			}

			return true;
		}

	public:
		void loadHook()
		{
			MH_CreateHook(
				(PVOID)(gd::base + 0x14c5b0),
				(LPVOID)AnimatedShopKeeper::initHook,
				(LPVOID*)&AnimatedShopKeeper::init
			);
		}
		
		static inline void weirdFunc(AnimatedShopKeeper* self, const char* string) {
			return reinterpret_cast<void(__thiscall*)(AnimatedShopKeeper*, const char*)>(gd::base + 0x145e0)(self, string);
		}

		static inline void weirdFunc2(AnimatedShopKeeper* self, int** param_1, int* param_2) {
			return reinterpret_cast<void(__thiscall*)(AnimatedShopKeeper*, int**, int*)>(gd::base + 0x145e0)(self, param_1, param_2);
		}
	};
}
