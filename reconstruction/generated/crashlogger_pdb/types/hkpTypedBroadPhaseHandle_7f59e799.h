// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpTypedBroadPhaseHandle; size 0xc
// one of 2 different PDB types sharing this name
#pragma once

#include "CFilter.h"
#include "hkpBroadPhaseHandle_e935101b.h"
struct hkpTypedBroadPhaseHandle_7f59e799 {
    hkpBroadPhaseHandle_e935101b _base;
    unsigned char type;
    unsigned char ownerOffset;
    unsigned char objectQualityType;
    unsigned char pad7;
    CFilter collisionFilterInfo;
};
static_assert(sizeof(hkpTypedBroadPhaseHandle_7f59e799) == 12, "hkpTypedBroadPhaseHandle_7f59e799 layout differs from the PDB");
