// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: HorseCameraState; size 0xf8
#pragma once

#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
#include "ThirdPersonState.h"
struct HorseCameraState {
    ThirdPersonState _base;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 horseRefHandle;
    float horseCurrentDirection;
    unsigned long long unkF0;
};
static_assert(sizeof(HorseCameraState) == 248, "HorseCameraState layout differs from the PDB");
