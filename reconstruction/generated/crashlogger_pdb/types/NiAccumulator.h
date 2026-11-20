// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiAccumulator; size 0x18
#pragma once

#include "NiObject_de5bc370.h"
struct NiCamera;
struct NiAccumulator {
    NiObject_de5bc370 _base;
    NiCamera* camera;
};
static_assert(sizeof(NiAccumulator) == 24, "NiAccumulator layout differs from the PDB");
