// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MagicTarget; size 0x18
// one of 2 different PDB types sharing this name
#pragma once

struct MagicTarget__SpellDispelData;
struct MagicTarget__VFTable;
struct MagicTarget_764e0294 {
    MagicTarget__VFTable* vftable_MagicTarget_0;
    MagicTarget__SpellDispelData* PostUpdateDispelList_8;
    unsigned char MagicTargetFlags_10;
    char _pad_11[7];
};
static_assert(sizeof(MagicTarget_764e0294) == 24, "MagicTarget_764e0294 layout differs from the PDB");
