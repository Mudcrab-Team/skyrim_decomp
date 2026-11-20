// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ActivateHandler; size 0x20
#pragma once

#include "HeldStateHandler.h"
struct ActivateHandler {
    HeldStateHandler _base;
    unsigned char unk18;
    unsigned char unk19;
    bool heldButtonActionSuccess;
    bool disabled;
    unsigned int unk1C;
};
static_assert(sizeof(ActivateHandler) == 32, "ActivateHandler layout differs from the PDB");
