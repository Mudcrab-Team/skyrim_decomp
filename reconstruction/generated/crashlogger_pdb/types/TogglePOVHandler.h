// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TogglePOVHandler; size 0x20
#pragma once

#include "HeldStateHandler.h"
struct TogglePOVHandler {
    HeldStateHandler _base;
    bool pressRegistered;
    unsigned char pad19;
    unsigned short pad1A;
    unsigned int pad1C;
};
static_assert(sizeof(TogglePOVHandler) == 32, "TogglePOVHandler layout differs from the PDB");
