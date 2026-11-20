// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: AutoVanityState; size 0x28
#pragma once

#include "TESCameraState.h"
struct AutoVanityState {
    TESCameraState _base;
    float autoVanityRot;
    unsigned int pad24;
};
static_assert(sizeof(AutoVanityState) == 40, "AutoVanityState layout differs from the PDB");
