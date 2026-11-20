// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiTransform; size 0x34
// one of 2 different PDB types sharing this name
#pragma once

#include "NiMatrix33.h"
#include "NiPoint3_a7124070.h"
struct NiTransform_333059e5 {
    NiMatrix33 Rotation_0;
    float Scale_30;
    NiPoint3_a7124070 Position_24;
};
static_assert(sizeof(NiTransform_333059e5) == 52, "NiTransform_333059e5 layout differs from the PDB");
