// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DefaultState; size 0x48
#pragma once

#include "NiPoint3.h"
#include "TESCameraState.h"
struct DefaultState {
    TESCameraState _base;
    NiPoint3 initialPosition;
    NiPoint3 translation;
    float zoom;
    float minFrustumHalfWidth;
    float minFrustumHalfHeight;
    unsigned int pad44;
};
static_assert(sizeof(DefaultState) == 72, "DefaultState layout differs from the PDB");
