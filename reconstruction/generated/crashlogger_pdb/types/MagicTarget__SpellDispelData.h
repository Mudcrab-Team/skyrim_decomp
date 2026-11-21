// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MagicTarget::SpellDispelData; size 0x18
#pragma once

#include "BSTSmartPointer_ActiveEffect_93b105c4.h"
struct MagicItem;
struct MagicTarget__SpellDispelData {
    MagicItem* Spell_0;
    unsigned int CasterRefHandle_8;
    char _pad_C[4];
    BSTSmartPointer_ActiveEffect_93b105c4 Effect_10;
    // overlaps an earlier member, left out: +0x10 Next_18
    unsigned char _pad_0[7];
};
static_assert(sizeof(MagicTarget__SpellDispelData) == 24, "MagicTarget__SpellDispelData layout differs from the PDB");
