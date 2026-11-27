// Source exposure: mixed (community headers; the pinned image listing; private sibling shape).
// Code origin: adapted from the private sibling; adapted bodies: SpellItem::GetChargeTime.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/SpellItem.cpp:189
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x155640 SpellItem::GetChargeTime
#include "SpellItem_155640.h"

// A hand-made spell charges for its set time; an auto-calculated one charges as long as its slowest effect.
float SpellItem::GetChargeTime() const
{
    float chargeTime = data.chargeTime;
    if (IsAutoCalc())
    {
        float slowest = 0.0f;
        for (std::uint32_t i = 0; i < effects.size(); i = i + 1)
        {
            if (!effects[i]->baseEffect->data.flagBit24)
            {
                float spellmakingChargeTime = effects[i]->baseEffect->data.spellmakingChargeTime;
                if (spellmakingChargeTime > slowest)
                {
                    slowest = spellmakingChargeTime;
                }
            }
        }
        return slowest;
    }
    return chargeTime;
}
