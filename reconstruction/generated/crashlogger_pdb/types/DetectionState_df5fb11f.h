// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DetectionState; size 0x48
// one of 2 different PDB types sharing this name
#pragma once

#include "NiPoint3_a7124070.h"
#include "NiRefObject.h"
struct DetectionState_df5fb11f {
    NiRefObject _base;
    int level;
    unsigned char hasLOS;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char pad17;
    float unk18;
    NiPoint3_a7124070 unk1C;
    float unk28;
    NiPoint3_a7124070 unk2C;
    float unk38;
    NiPoint3_a7124070 unk3C;
};
static_assert(sizeof(DetectionState_df5fb11f) == 72, "DetectionState_df5fb11f layout differs from the PDB");
