// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TweenMenuCameraState; size 0x50
#pragma once

#include "NiPoint2_6bdffc9f.h"
#include "NiQuaternion.h"
#include "TESCameraState.h"
struct TweenMenuCameraState {
    TESCameraState _base;
    NiQuaternion intialRotation;
    float initialFOV;
    NiPoint2_6bdffc9f currentAddedRot;
    NiPoint2_6bdffc9f targetAddedRot;
    float currentAddedFOV;
    float targetAddedFOV;
    bool endingState;
    unsigned char pad4D;
    unsigned short pad4E;
};
static_assert(sizeof(TweenMenuCameraState) == 80, "TweenMenuCameraState layout differs from the PDB");
