#ifndef GAME_H
#define GAME_H

#include "../proc/process.h"
#include "entities/LocalPlayer.h"

class Game
{
private:
	HANDLE hProcess;
	uintptr_t moduleBase;

public:
	Game(DWORD PID);

	LocalPlayer localPlayer;

	void writeMem(unsigned int base, std::vector<unsigned int> offsets, _In_reads_bytes_(nSize) LPCVOID lpBuffer, _In_ SIZE_T nSize);
};

#endif // GAME_H
