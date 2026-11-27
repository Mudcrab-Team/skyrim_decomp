// Source exposure: mixed (local target observations; community declarations; permitted sibling game code).
// Code origin: adapted permitted sibling body, checked against the local target.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ValueModifierEffect.cpp:100
// Adapted bodies: ValueModifierEffect::IsZeroDurationException from the cited sibling, author-permission.
// 0x5e70e0 ValueModifierEffect::IsZeroDurationException
// TestFlag: GUESS(low); by-value bit-index accessor.
// TestFlag is original source following cookbook rule 16; its generic expression is not a sibling adaptation.
#include "ValueModifierEffect_5e70e0.h"

static bool TestFlag(std::uint32_t value, unsigned bit)
{
    return (value >> bit) & 1;
}

bool ValueModifierEffect::IsZeroDurationException() const
{
    bool result = false;
    if (TestFlag(flags, 8) || spell->GetCastingType() == MagicSystem::CastingType::kConcentration)
        result = true;
    else
    {
        switch (spell->GetSpellType())
        {
        case MagicSystem::SpellType::kDisease:
        case MagicSystem::SpellType::kAbility:
            result = true;
            break;
        default:
            break;
        }
    }
    return result;
}
