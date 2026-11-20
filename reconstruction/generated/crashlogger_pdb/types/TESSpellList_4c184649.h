// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESSpellList; size 0x10
// one of 2 different PDB types sharing this name
#pragma once

#include "BaseFormComponent.h"
struct SpellData;
struct TESSpellList_4c184649 {
    BaseFormComponent _base;
    SpellData* actorEffects;
};
static_assert(sizeof(TESSpellList_4c184649) == 16, "TESSpellList_4c184649 layout differs from the PDB");
