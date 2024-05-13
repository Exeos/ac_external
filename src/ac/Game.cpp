#include "Game.h"

Game::Game(DWORD PID) : localPlayer(this) {
    Game::hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, PID);
    Game::moduleBase = GetModuleBaseAddress(PID, L"ac_client.exe");
}

void Game::writeMem(unsigned int base, std::vector<unsigned int> offsets, _In_reads_bytes_(nSize) LPCVOID lpBuffer, _In_ SIZE_T nSize) {
    WriteProcessMemory(
        Game::hProcess,
        (BYTE*)FindMAAddy(Game::hProcess, Game::moduleBase + base, offsets),
        lpBuffer,
        nSize,
        NULL
    );
}