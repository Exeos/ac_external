#include "LocalPlayer.h"
#include "../Game.h"

LocalPlayer::LocalPlayer(Game* gamePtr) : game(gamePtr) {}

void LocalPlayer::setOnGround(bool onGround) {
	LocalPlayer::game->writeMem(LocalPlayer::offsets.base, LocalPlayer::offsets.onGround, &onGround, sizeof(onGround));
}

void LocalPlayer::setHealt(int health) {
	LocalPlayer::game->writeMem(LocalPlayer::offsets.base, LocalPlayer::offsets.health, &health, sizeof(health));
}

void LocalPlayer::setAmmo(int ammo) {
	LocalPlayer::game->writeMem(LocalPlayer::offsets.base, LocalPlayer::offsets.ammo, &ammo, sizeof(ammo));
}