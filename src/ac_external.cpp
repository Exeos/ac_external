

#include <iostream>
#include "proc/process.h"


int main()
{
    std::cout << "waiting for ac_client.exe" << std::endl;

    DWORD PID = NULL;
    do {
        PID = GetPID(L"ac_client.exe");
    } while (PID == NULL);

    std::cout << "found ac_client.exe -> " << PID << std::endl;

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, PID);
    uintptr_t moduleBase = GetModuleBaseAddress(PID, L"ac_client.exe");



    unsigned int playerBaseOffset = 0x0017E0A8;
    std::vector<unsigned int> playerOnGroundOffset = { 0x5D };
    std::vector<unsigned int> playerHealthOffset = { 0xEC };
    std::vector<unsigned int> playerAmmoOffset = { 0x140 };

    bool onground = true;
    int health = 9999;
    int ammo = 9999;

    while (true) {
        WriteProcessMemory(
            hProcess,
            (BYTE*)FindMAAddy(hProcess, moduleBase + playerBaseOffset, playerOnGroundOffset),
            &onground,
            sizeof(onground),
            NULL
        );

        WriteProcessMemory(
            hProcess,
            (BYTE*)FindMAAddy(hProcess, moduleBase + playerBaseOffset, playerHealthOffset),
            &health,
            sizeof(health),
            NULL
        );

        WriteProcessMemory(
            hProcess,
            (BYTE*)FindMAAddy(hProcess, moduleBase + playerBaseOffset, playerAmmoOffset),
            &ammo,
            sizeof(ammo),
            NULL
        );
    }
}

