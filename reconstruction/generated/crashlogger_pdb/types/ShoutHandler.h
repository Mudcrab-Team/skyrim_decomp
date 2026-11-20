// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ShoutHandler; size 0x20
#pragma once

#include "PlayerInputHandler.h"
struct ShoutHandler {
    PlayerInputHandler _base;
    unsigned long long unk10;
    unsigned long long unk18;
};
static_assert(sizeof(ShoutHandler) == 32, "ShoutHandler layout differs from the PDB");
