// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: LookHandler; size 0xb8
#pragma once

#include "PlayerInputHandler.h"
struct LookHandler {
    PlayerInputHandler _base;
    unsigned char undefined_10[168];
};
static_assert(sizeof(LookHandler) == 184, "LookHandler layout differs from the PDB");
