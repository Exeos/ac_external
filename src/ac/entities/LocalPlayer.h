#ifndef LOCALPLAYER_H
#define LOCALPLAYER_H

#include <vector>

class Game; // Forward declaration

class LocalPlayer
{
private:
	Game* game;
	struct {
		unsigned int base = 0x0017E0A8;

		std::vector<unsigned int> onGround = { 0x5D };
		std::vector<unsigned int> health = { 0xEC };
		std::vector<unsigned int> ammo = { 0x140 };
	} offsets;
public:
	LocalPlayer(Game* gamePtr);

	void setOnGround(bool onGround);
	void setHealt(int health);
	void setAmmo(int ammo);
};

#endif // LOCALPLAYER_H