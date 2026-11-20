// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESCameraState; size 0x20
// one of 2 different PDB types sharing this name
#pragma once

#include "CameraState_061b88bf.h"
struct TESCameraState__VFTable;
struct TESCamera_ba12c162;
struct TESCameraState_b107d5ca {
    TESCameraState__VFTable* vftable_TESCameraState_0;
    int refCount_8;
    char _pad_C[4];
    TESCamera_ba12c162* Camera_10;
    CameraState_061b88bf Id_18;
    char _pad_1C[4];
};
static_assert(sizeof(TESCameraState_b107d5ca) == 32, "TESCameraState_b107d5ca layout differs from the PDB");
