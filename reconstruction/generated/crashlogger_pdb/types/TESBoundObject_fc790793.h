// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESBoundObject; size 0x30
// one of 2 different PDB types sharing this name
#pragma once

#include "BOUND_DATA.h"
#include "TESObject_2ec9fb8f.h"
struct TESBoundObject_fc790793 {
    TESObject_2ec9fb8f _base;
    BOUND_DATA boundData;
    unsigned int pad2C;
};
static_assert(sizeof(TESBoundObject_fc790793) == 48, "TESBoundObject_fc790793 layout differs from the PDB");
