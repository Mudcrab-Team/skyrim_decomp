// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DragonCameraState; size 0x110
#pragma once

#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
#include "ThirdPersonState.h"
struct DragonCameraState {
    ThirdPersonState _base;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 dragonHandle;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    bool lockedOnTarget;
    unsigned char padF9[3];
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 targetLockHandle;
};
static_assert(sizeof(DragonCameraState) == 272, "DragonCameraState layout differs from the PDB");
