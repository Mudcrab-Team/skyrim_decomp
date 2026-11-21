// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSAttackDataForm; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BaseFormComponent.h"
#include "NiPointer_RE__BGSAttackDataMap_4029c1a3.h"
struct BGSAttackDataForm {
    BaseFormComponent _base;
    NiPointer_RE__BGSAttackDataMap_4029c1a3 attackDataMap;
};
static_assert(sizeof(BGSAttackDataForm) == 16, "BGSAttackDataForm layout differs from the PDB");
