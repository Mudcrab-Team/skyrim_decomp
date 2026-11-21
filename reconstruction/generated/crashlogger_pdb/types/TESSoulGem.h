// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESSoulGem; size 0x110
#pragma once

#include "TESObjectMISC.h"
struct TESSoulGem {
    TESObjectMISC _base;
    TESSoulGem* linkedSoulGem;
    unsigned char currentSoul;  // SOUL_LEVEL in the PDB is wider than this slot
    unsigned char soulCapacity;  // SOUL_LEVEL in the PDB is wider than this slot
    unsigned short unk10A;
    unsigned int unk10C;
};
static_assert(sizeof(TESSoulGem) == 272, "TESSoulGem layout differs from the PDB");
