// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FreeCameraState; size 0x50
#pragma once

#include "BSTPoint2_float_af46c5cb.h"
#include "NiPoint3.h"
#include "PlayerInputHandler.h"
#include "TESCameraState.h"
struct FreeCameraState {
    TESCameraState _base;
    PlayerInputHandler _base_PlayerInputHandler;
    NiPoint3 translation;
    BSTPoint2_float_af46c5cb rotation;
    BSTPoint2_float_af46c5cb zUpDown;
    short verticalDirection;
    bool useRunSpeed;
    bool lockToZPlane;
};
static_assert(sizeof(FreeCameraState) == 80, "FreeCameraState layout differs from the PDB");
