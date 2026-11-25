// 0x82ec10 CombatInventoryItemMagic::CalculateCategoryMultiplier
// Code origin: original reconstruction from local binary analysis; community declarations only.
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CombatInventoryItemMagic, CombatController, TESCombatStyle, CombatStyleGeneralData, generalData, combatStyle, magicScoreMult, shoutScoreMult, staffScoreMult: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CalculateCategoryMultiplier, scoreThreshold, scoreMultiplier: GUESS(low); behavior-derived helper and data names.
#include "CombatInventoryItemMagic_82ec10.h"

extern float scoreThreshold;
extern float scoreMultiplier;

float CombatInventoryItemMagic::CalculateCategoryMultiplier(const CombatController* controller, const void*, int category, float value)
{
    float multiplier = 1.0f;
    switch (category) {
    case 4: multiplier = controller->combatStyle->generalData.magicScoreMult; break;
    case 5: multiplier = controller->combatStyle->generalData.shoutScoreMult; break;
    case 6: multiplier = controller->combatStyle->generalData.staffScoreMult; break;
    }
    if (value > scoreThreshold)
        multiplier *= scoreMultiplier;
    return multiplier;
}
