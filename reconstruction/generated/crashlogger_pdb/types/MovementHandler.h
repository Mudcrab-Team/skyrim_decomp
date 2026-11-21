// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MovementHandler; size 0x10
#pragma once

#include "PlayerInputHandler.h"
struct MovementHandler {
    PlayerInputHandler _base;
};
static_assert(sizeof(MovementHandler) == 16, "MovementHandler layout differs from the PDB");
