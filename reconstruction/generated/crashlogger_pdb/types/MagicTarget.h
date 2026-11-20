// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MagicTarget; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct MagicTarget_vtbl;
struct SpellDispelData;
struct MagicTarget {
    MagicTarget_vtbl* __vftable;
    SpellDispelData* postUpdateDispelList;
    unsigned short pad10;
    unsigned short pad12;
    unsigned int pad14;
};
static_assert(sizeof(MagicTarget) == 24, "MagicTarget layout differs from the PDB");
