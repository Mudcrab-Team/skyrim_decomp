// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESCameraState; size 0x20
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSIntrusiveRefCounted.h"
#include "CameraState.h"
struct TESCamera;
struct TESCameraState_vtbl;
struct TESCameraState {
    TESCameraState_vtbl* __vftable;
    BSIntrusiveRefCounted _base_BSIntrusiveRefCounted;
    unsigned int pad0C;
    TESCamera* camera;
    CameraState id;
    unsigned int pad1C;
};
static_assert(sizeof(TESCameraState) == 32, "TESCameraState layout differs from the PDB");
