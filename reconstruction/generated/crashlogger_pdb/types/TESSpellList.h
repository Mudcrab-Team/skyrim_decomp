// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESSpellList; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct TESSpellList__Data;
struct TESSpellList__VFTable;
struct TESSpellList {
    TESSpellList__VFTable* vftable_TESSpellList_0;
    TESSpellList__Data* ActorEffects_8;
};
static_assert(sizeof(TESSpellList) == 16, "TESSpellList layout differs from the PDB");
