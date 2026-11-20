// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSBaseAlias; size 0x28
// one of 2 different PDB types sharing this name
#pragma once

#include "FLAGS_d4eab9c4.h"
struct BGSBaseAlias_vtbl;
struct TESQuest;
struct BGSBaseAlias_fa331a96 {
    BGSBaseAlias_vtbl* __vftable;
    unsigned char aliasName_raw[8];
    TESQuest* owningQuest;
    unsigned int aliasID;
    FLAGS_d4eab9c4 flags;
    unsigned short fillType;  // FILL_TYPE in the PDB is wider than this slot
    unsigned short pad22;
    unsigned int pad24;
};
static_assert(sizeof(BGSBaseAlias_fa331a96) == 40, "BGSBaseAlias_fa331a96 layout differs from the PDB");
