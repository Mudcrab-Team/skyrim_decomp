// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: OBJ_REFR; size 0x20
#pragma once

#include "NiPoint3.h"
struct TESBoundObject_fc790793;
struct OBJ_REFR {
    TESBoundObject_fc790793* objectReference;
    NiPoint3 angle;
    NiPoint3 location;
};
static_assert(sizeof(OBJ_REFR) == 32, "OBJ_REFR layout differs from the PDB");
