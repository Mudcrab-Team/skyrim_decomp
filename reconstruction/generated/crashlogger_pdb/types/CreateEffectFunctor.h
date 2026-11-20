// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CreateEffectFunctor; size 0x58
#pragma once

#include "BSTArray_RE__Effect_6e8b47bd.h"
#include "MagicItemTraversalFunctor.h"
struct Effect;
struct EnchantmentEntry;
struct EnchantmentItem_57a0edce;
struct TESForm;
struct CreateEffectFunctor {
    MagicItemTraversalFunctor _base;
    BSTArray_RE__Effect_6e8b47bd createdEffects;
    Effect* costliestEffect;
    EnchantmentEntry* enchantmentParams;
    EnchantmentItem_57a0edce* createdEnchantment;
    unsigned char formType_raw[8];
    TESForm* baseObject;
    float soulGemRatio;
    unsigned int pad5C;
};
static_assert(sizeof(CreateEffectFunctor) == 88, "CreateEffectFunctor layout differs from the PDB");
