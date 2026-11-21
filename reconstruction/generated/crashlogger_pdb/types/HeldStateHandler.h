// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: HeldStateHandler; size 0x18
#pragma once

#include "PlayerInputHandler.h"
struct HeldStateHandler {
    PlayerInputHandler _base;
    bool heldStateActive;
    bool triggerReleaseEvent;
    unsigned short pad12;
    unsigned int pad14;
};
static_assert(sizeof(HeldStateHandler) == 24, "HeldStateHandler layout differs from the PDB");
