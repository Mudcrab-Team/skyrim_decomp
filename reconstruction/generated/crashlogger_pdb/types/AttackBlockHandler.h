// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: AttackBlockHandler; size 0xc0
#pragma once

#include "HeldStateHandler.h"
struct AttackBlockHandler {
    HeldStateHandler _base;
    unsigned char _pad18[168];
};
static_assert(sizeof(AttackBlockHandler) == 192, "AttackBlockHandler layout differs from the PDB");
