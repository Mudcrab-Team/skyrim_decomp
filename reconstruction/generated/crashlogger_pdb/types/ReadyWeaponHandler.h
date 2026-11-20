// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ReadyWeaponHandler; size 0x10
#pragma once

#include "PlayerInputHandler.h"
struct ReadyWeaponHandler {
    PlayerInputHandler _base;
};
static_assert(sizeof(ReadyWeaponHandler) == 16, "ReadyWeaponHandler layout differs from the PDB");
