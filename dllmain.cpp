// dllmain.cpp : Defines the entry point for the DLL application.

#include "pch.h"
#include <Windows.h>
#include <cstdio>
#include <iostream>

#include "memcury.h"

void FinderConsole()
{
    AllocConsole();
    FILE* File;
    freopen_s(&File, "CONOUT$", "w", stdout);

    SetConsoleTitleA("Finder7 | By yetzq7");
    std::cout << "Starting Finder7.." << "\n";

}

DWORD WINAPI FinderSeven(LPVOID lpParam)
{
    FinderConsole();
    // initial patterns
    auto CreateNetDriver = Memcury::Scanner::FindPattern("49 8B D8 48 8B F9 E8 ?? ?? ?? ?? 48 8B D0 4C 8B C3 48 8B CF 48 8B 5C 24 ?? 48 83 C4 ?? 5F E9 ?? ?? ?? ??");
    auto InitListen = Memcury::Scanner::FindPattern("4C 8B DC 49 89 5B ? 49 89 73 ? 57 48 83 EC ? 48 8B BC 24");
    auto PickTeam = Memcury::Scanner::FindPattern("88 54 24 10 53 56 41 54 41 55 41 56 48 83 EC 60 4C 8B A1");
    auto GetNetMode = Memcury::Scanner::FindPattern("48 83 EC 28 48 83 79 ? ? 75 20 48 8B 91 ? ? ? ? 48 85 D2 74 1E 48 8B 02 48 8B CA FF 90");
    auto TickFlush = Memcury::Scanner::FindPattern("4C 8B DC 55 53 56 57 49 8D AB ? ? ? ? 48 81 EC ? ? ? ? 41 0F 29 7B");
    auto GetMaxTickRate = Memcury::Scanner::FindPattern("48 8B C4 48 89 58 ? 48 89 68 ? 48 89 70 ? 57 41 55 41 56 48 83 EC ? 0F 29 70 ? 48 8B D9 0F 29");
    auto ReplicateActor = Memcury::Scanner::FindPattern("40 55 53 57 41 56 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 48 8D 59 68 4C 8B F1 48 8B");

    // if initial patterns fail then it will try and use patterns from these below

    if (!CreateNetDriver.Get())

        CreateNetDriver = Memcury::Scanner::FindPattern("E8 ?? ?? ?? ?? 4C 8B 44 24 ?? 48 8B D0 48 8B CB E8 ?? ?? ?? ?? 48 83 C4 ?? 5B C3");


    if (!CreateNetDriver.Get())

        CreateNetDriver = Memcury::Scanner::FindPattern("33 D2 E8 ?? ?? ?? ?? 48 8B D0 4C 8B C3 48 8B CF E8 ?? ?? ?? ?? 48 8B 5C 24 ?? 48 83 C4 ?? 5F C3");


    //pickteam

    if (!PickTeam.Get())

        PickTeam = Memcury::Scanner::FindPattern("88 54 24 10 53 55 56 41 55 41 ? 48 83 EC 70 48");


    if (!PickTeam.Get())

        PickTeam = Memcury::Scanner::FindPattern("89 54 24 10 53 56 41 54 41 55 41 56 48 81 EC");


    //tickflush

    if (!TickFlush.Get())
        TickFlush = Memcury::Scanner::FindPattern("4C 8B DC 55 49 8D AB ? ? ? ? 48 81 EC ? ? ? ? 45 0F 29 43 ? 45 0F 29 4B ? 48 8B 05 ? ? ? ? 48");


    if (!TickFlush.Get())
        TickFlush = Memcury::Scanner::FindPattern("48 8B C4 48 89 58 18 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 0F 29 70 B8 0F 29 78 A8 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 8A");


    if (!TickFlush.Get())
        TickFlush = Memcury::Scanner::FindPattern("48 8B C4 48 89 58 18 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 0F 29 70 B8 0F 29 78 A8 48 8B ");

    if (!TickFlush.Get())
        TickFlush = Memcury::Scanner::FindPattern("05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 44 0F");


    if (!TickFlush.Get())
        TickFlush = Memcury::Scanner::FindPattern("48 8B C4 48 89 58 18 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 0F 29 70 B8 0F 29 78 A8 48 8B ");

    if (!TickFlush.Get())
        TickFlush = Memcury::Scanner::FindPattern("05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 48 8B F9 48 89 4D 38 48 8D 4D 40");

    //initlisten

    if (!InitListen.Get())
        InitListen = Memcury::Scanner::FindPattern("4C 8B DC 49 89 5B 08 49 89 73 10 57 48 83 EC 40 48 8B 7C 24 ? 49 8B F0 48 8B 01 48 8B D9 49 89 7B E0 45");

    if (!InitListen.Get())
        InitListen = Memcury::Scanner::FindPattern("4C 8B DC 49 89 5B 08 49 89 73 10 57 48 83 EC 50 48 8B BC 24 ? ? ? ? 49 8B F0 48 8B 01 48 8B");

    //maxtickrate

    if (!GetMaxTickRate.Get())
        GetMaxTickRate = Memcury::Scanner::FindPattern("40 53 48 83 EC 50 0F 29 74 24 ? 48 8B D9 0F 29 7C 24 ? 0F 28 F9 44 0F 29");

    if (!GetMaxTickRate.Get())
        GetMaxTickRate = Memcury::Scanner::FindPattern("48 8B C4 48 89 58 ? 48 89 68 ? 48 89 70 ? 57 41 54 41 56 48 83 EC ? 0F 29 70 ? 48 8B D9");

    if (!GetMaxTickRate.Get())
        GetMaxTickRate = Memcury::Scanner::FindPattern("40 53 48 83 EC 60 0F 29 74 24 ? 48 8B D9 0F 29 7C 24 ? 0F 28");

    //replicateactor

    if (!ReplicateActor.Get())
        ReplicateActor = Memcury::Scanner::FindPattern("48 8B C4 55 53 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 0F 29 70 A8 0F 29 78 98 48 89 70 E8 4C");

    if (!ReplicateActor.Get())
        ReplicateActor = Memcury::Scanner::FindPattern("40 55 56 57 41 54 41 55 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 4C");

    if (!ReplicateActor.Get())
        ReplicateActor = Memcury::Scanner::FindPattern("40 55 56 41 54 41 55 41 56 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 4C 8B E9 48 8B 49 68 48");


    uintptr_t Base = (uintptr_t)GetModuleHandleA(nullptr);


    std::cout << "- Offsets generated!" << "\n";

    if (CreateNetDriver.Get()) {
        std::cout << "CreateNetDriver: 0x" << std::hex << (CreateNetDriver.Get() - Base) << "\n";
    }
    else {
        std::cout << "CreateNetDriver: not found" << "\n";
    }


    if (InitListen.Get()) {
        std::cout << "InitListen: 0x" << std::hex << (InitListen.Get() - Base) << "\n";
    }
    else {
        std::cout << "InitListen: not found" << "\n";
    }


    if (PickTeam.Get()) {
        std::cout << "PickTeam: 0x" << std::hex << (PickTeam.Get() - Base) << "\n";
    }
    else {
        std::cout << "PickTeam: not found" << "\n";
    }


    if (GetMaxTickRate.Get()) {
        std::cout << "GetMaxTickRate: 0x" << std::hex << (GetMaxTickRate.Get() - Base) << "\n";
    }
    else {
        std::cout << "GetMaxTickRate: not found" << "\n";
    }

    if (ReplicateActor.Get()) {
        std::cout << "ReplicateActor: 0x" << std::hex << (ReplicateActor.Get() - Base) << "\n";
    }
    else {
        std::cout << "ReplicateActor: not found" << "\n";
    }

    if (GetNetMode.Get()) {
        std::cout << "GetNetMode: 0x" << std::hex << (GetNetMode.Get() - Base) << "\n";
    }
    else {
        std::cout << "GetNetMode: not found" << "\n";
    }


    if (TickFlush.Get()) {
        std::cout << "TickFlush: 0x" << std::hex << (TickFlush.Get() - Base) << "\n";
    }
    else {
        std::cout << "TickFlush: not found" << "\n";
    }



    return 0;
}

BOOL APIENTRY DllMain(
    HMODULE hModule,
    DWORD ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        CreateThread(nullptr, 0, FinderSeven, nullptr, 0, nullptr);
        break;

    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }

    return TRUE;
}