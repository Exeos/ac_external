

#include <iostream>
#include "proc/process.h"
#include "ac/Game.h"

int main()
{
    std::cout << "waiting for ac_client.exe" << std::endl;

    DWORD PID = NULL;
    do {
        PID = GetPID(L"ac_client.exe");
    } while (PID == NULL);

    std::cout << "found ac_client.exe -> " << PID << std::endl;


    Game game = Game(PID);
    LocalPlayer* player = &game.localPlayer;
    while (true)
    {
        (*player).setOnGround(true);
        (*player).setHealt(999);
        (*player).setAmmo(999);
    }
}

