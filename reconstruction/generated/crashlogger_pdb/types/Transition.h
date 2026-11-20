// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Transition; size 0x88
#pragma once

#include "NiPoint3.h"
#include "TESCameraState.h"
struct Transition {
    TESCameraState _base;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    NiPoint3 currentPosition;
    NiPoint3 zoomDestination;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned char zoomOrigin_raw[16];
    unsigned char pad[24];
};
static_assert(sizeof(Transition) == 136, "Transition layout differs from the PDB");
