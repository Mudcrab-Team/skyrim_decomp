// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SneakHandler; size 0x10
#pragma once

#include "PlayerInputHandler.h"
struct SneakHandler {
    PlayerInputHandler _base;
};
static_assert(sizeof(SneakHandler) == 16, "SneakHandler layout differs from the PDB");
