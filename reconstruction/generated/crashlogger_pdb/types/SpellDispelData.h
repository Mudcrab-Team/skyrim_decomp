// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SpellDispelData; size 0x20
#pragma once

#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
#include "BSTSmartPointer_RE__ActiveEffect_fc15ffff.h"
struct MagicItem_34516af4;
struct SpellDispelData {
    MagicItem_34516af4* spell;
    BSPointerHandle_RE__Actor_1a35f4b9 caster;
    unsigned int pad0C;
    BSTSmartPointer_RE__ActiveEffect_fc15ffff activeEffect;
    SpellDispelData* next;
};
static_assert(sizeof(SpellDispelData) == 32, "SpellDispelData layout differs from the PDB");
