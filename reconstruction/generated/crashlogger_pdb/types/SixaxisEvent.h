// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SixaxisEvent; size 0x90
#pragma once

#include "IDEvent.h"
#include "NiQuaternion.h"
#pragma pack(push, 4)
struct SixaxisEvent {
    IDEvent _base;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned long long unk30;
    unsigned long long unk38;
    unsigned int unk40;
    unsigned long long unk44;
    unsigned int unk4C;
    unsigned long long unk50;
    unsigned int unk58;
    unsigned long long unk5C;
    unsigned int unk64;
    unsigned long long unk68;
    unsigned int unk70;
    unsigned long long unk74;
    unsigned int unk7C;
    NiQuaternion orientation;
};
#pragma pack(pop)
static_assert(sizeof(SixaxisEvent) == 144, "SixaxisEvent layout differs from the PDB");
