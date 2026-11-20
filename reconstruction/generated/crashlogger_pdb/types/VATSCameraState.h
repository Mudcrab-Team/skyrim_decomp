// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: VATSCameraState; size 0x38
#pragma once

#include "TESCameraState.h"
struct VATSCameraState {
    TESCameraState _base;
    unsigned long long unk20;
    unsigned long long unk28;
    unsigned long long unk30;
};
static_assert(sizeof(VATSCameraState) == 56, "VATSCameraState layout differs from the PDB");
