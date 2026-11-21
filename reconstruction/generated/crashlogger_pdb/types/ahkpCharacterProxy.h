// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ahkpCharacterProxy; size 0x100
#pragma once

#include "hkpCharacterProxy.h"
struct ahkpCharacterProxy {
    hkpCharacterProxy _base;
    unsigned long long unk0F0;
    unsigned long long unk0F8;
};
static_assert(sizeof(ahkpCharacterProxy) == 256, "ahkpCharacterProxy layout differs from the PDB");
