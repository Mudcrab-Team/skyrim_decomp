// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSBaseAlias; size 0x28
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "FLAGS.h"
struct BGSBaseAlias_vtbl_d9982b4c;
struct TESQuest_fe66f8e1;
struct BGSBaseAlias {
    BGSBaseAlias_vtbl_d9982b4c* __vftable;
    BSFixedString_char_83b572b4 aliasName;
    TESQuest_fe66f8e1* owningQuest;
    unsigned int aliasID;
    FLAGS flags;
    unsigned short fillType;  // FILL_TYPE in the PDB is wider than this slot
    unsigned short pad22;
    unsigned int pad24;
};
static_assert(sizeof(BGSBaseAlias) == 40, "BGSBaseAlias layout differs from the PDB");
