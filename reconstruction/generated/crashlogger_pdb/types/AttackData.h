// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: AttackData; size 0x38
#pragma once

#include "AttackFlag.h"
struct BGSKeyword;
struct SpellItem_847bf892;
struct AttackData {
    float damageMult;
    float attackChance;
    SpellItem_847bf892* attackSpell;
    AttackFlag flags;
    float attackAngle;
    float strikeAngle;
    float staggerOffset;
    BGSKeyword* attackType;
    float knockDown;
    float recoveryTime;
    float staminaMult;
    unsigned int pad34;
};
static_assert(sizeof(AttackData) == 56, "AttackData layout differs from the PDB");
