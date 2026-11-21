// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Exit; size 0x20
#pragma once

#include "TESCameraState.h"
struct Exit {
    TESCameraState _base;
};
static_assert(sizeof(Exit) == 32, "Exit layout differs from the PDB");
