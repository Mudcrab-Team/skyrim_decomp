// Code origin: original reconstruction from local binary analysis; community declarations only.
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CombatInventoryItemMagic, CombatController, TESCombatStyle, CombatStyleGeneralData, generalData, combatStyle, magicScoreMult, shoutScoreMult, staffScoreMult: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CombatController, TESCombatStyle, CombatStyleGeneralData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CalculateCategoryMultiplier, unknown00, unknown20, unknown34, unknown3C: GUESS(low); helper identity and unused storage are unresolved.
#pragma once

#include <cstddef>

struct CombatStyleGeneralData
{
    unsigned char unknown00[0x10];
    float magicScoreMult;
    unsigned char unknown34[4];
    float shoutScoreMult;
    unsigned char unknown3C[4];
    float staffScoreMult;
};

struct TESCombatStyle
{
    unsigned char unknown20[0x20];
    CombatStyleGeneralData generalData;
};

struct CombatController
{
    unsigned char unknown00[0x38];
    TESCombatStyle* combatStyle;
};

class CombatInventoryItemMagic
{
public:
    // Static ownership and unused argument type are unresolved.
    static float CalculateCategoryMultiplier(const CombatController* controller, const void* unused, int category, float value);
};
static_assert(offsetof(CombatController, combatStyle) == 0x38, "combat style offset");
static_assert(offsetof(TESCombatStyle, generalData) + offsetof(CombatStyleGeneralData, staffScoreMult) == 0x40, "staff multiplier offset");
