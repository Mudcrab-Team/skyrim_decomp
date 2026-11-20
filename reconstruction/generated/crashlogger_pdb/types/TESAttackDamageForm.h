// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESAttackDamageForm; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BaseFormComponent.h"
struct TESAttackDamageForm {
    BaseFormComponent _base;
    unsigned short attackDamage;
    unsigned short pad0A;
    unsigned int pad0C;
};
static_assert(sizeof(TESAttackDamageForm) == 16, "TESAttackDamageForm layout differs from the PDB");
