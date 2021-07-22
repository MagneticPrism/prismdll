// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "util/Mod.h"

__declspec(dllexport) DWORD WINAPI Entry(void* hModule) {
    
    if (MH_Initialize() != MH_OK) {
        MessageBoxA(nullptr, "prismdll: Unable to initialize MinHook!", "Error", MH_OK);
        FreeLibraryAndExitThread(reinterpret_cast<HMODULE>(hModule), 0);
        return 0;
    }

    prismdll::Mod::startHooks();

    MH_EnableHook(MH_ALL_HOOKS);
        
    while (true);
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0x1000, Entry, hModule, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
