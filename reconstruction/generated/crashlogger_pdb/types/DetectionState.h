// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DetectionState; size 0x48
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "NiPoint3.h"
#include "NiRefObject_f24a9221.h"
struct DetectionState {
    NiRefObject_f24a9221 _base;
    int level;
    unsigned char hasLOS;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char pad17;
    float unk18;
    NiPoint3 unk1C;
    float unk28;
    NiPoint3 unk2C;
    float unk38;
    NiPoint3 unk3C;
};
static_assert(sizeof(DetectionState) == 72, "DetectionState layout differs from the PDB");
