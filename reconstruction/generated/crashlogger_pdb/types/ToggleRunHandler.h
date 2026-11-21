// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ToggleRunHandler; size 0x10
#pragma once

#include "PlayerInputHandler.h"
struct ToggleRunHandler {
    PlayerInputHandler _base;
};
static_assert(sizeof(ToggleRunHandler) == 16, "ToggleRunHandler layout differs from the PDB");
