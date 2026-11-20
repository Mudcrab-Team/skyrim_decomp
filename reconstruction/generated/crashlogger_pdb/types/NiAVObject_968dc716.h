// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiAVObject; size 0x110
// one of 2 different PDB types sharing this name
#pragma once

#include "NiAVObjectFlag.h"
struct TESObjectREFR;
struct NiAVObject_968dc716 {
    unsigned char _base_raw[48];
    unsigned char parent_raw[8];
    unsigned int parentIndex;
    unsigned int unk03C;
    unsigned char collisionObject_raw[8];
    unsigned char local_raw[52];
    unsigned char world_raw[52];
    unsigned char previousWorld_raw[52];
    unsigned char worldBound_raw[16];
    NiAVObjectFlag flags;
    TESObjectREFR* userData;
    float fadeAmount;
    unsigned int lastUpdatedFrameCounter;
    unsigned char lodMode;
    unsigned char flags02;
    unsigned short unk10A;
    unsigned int pad10C;
};
static_assert(sizeof(NiAVObject_968dc716) == 272, "NiAVObject_968dc716 layout differs from the PDB");
