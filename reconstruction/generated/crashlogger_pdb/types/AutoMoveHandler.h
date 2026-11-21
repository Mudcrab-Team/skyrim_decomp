// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: AutoMoveHandler; size 0x10
#pragma once

#include "PlayerInputHandler.h"
struct AutoMoveHandler {
    PlayerInputHandler _base;
};
static_assert(sizeof(AutoMoveHandler) == 16, "AutoMoveHandler layout differs from the PDB");
