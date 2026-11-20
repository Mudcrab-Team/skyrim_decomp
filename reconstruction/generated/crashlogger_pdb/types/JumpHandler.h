// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: JumpHandler; size 0x10
#pragma once

#include "PlayerInputHandler.h"
struct JumpHandler {
    PlayerInputHandler _base;
};
static_assert(sizeof(JumpHandler) == 16, "JumpHandler layout differs from the PDB");
