// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FurnitureCameraState; size 0x40
#pragma once

#include "NiPoint3.h"
#include "TESCameraState.h"
struct FurnitureCameraState {
    TESCameraState _base;
    unsigned int unk20;
    NiPoint3 unk24;
    unsigned long long unk30;
    unsigned int unk38;
    unsigned short unk3C;
    unsigned short unk3E;
};
static_assert(sizeof(FurnitureCameraState) == 64, "FurnitureCameraState layout differs from the PDB");
