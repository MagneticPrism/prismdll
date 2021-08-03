#pragma once

#include "../pch.h"
#include <gd.h>

namespace prismdll
{
    class GameManager : public gd::GManager
    {
    protected:
        static inline bool(__thiscall* isIconUnlocked)(GameManager, uintptr_t, int, gd::IconType);
        static bool isIconUnlockedHook(GameManager self, uintptr_t edx, int iconID, gd::IconType iconType)
        {
            if (iconType == gd::kIconTypeCube && iconID > 142)
            {
                return true;
            }

            return isIconUnlocked(self, edx, iconID, iconType);
        }

    public:
        static void loadHook()
        {
            MH_CreateHook(
                (PVOID)(gd::base + 0xc4fc0),
                (LPVOID)GameManager::isIconUnlockedHook,
                (LPVOID*)&GameManager::isIconUnlocked
            );
        }
    };
}
