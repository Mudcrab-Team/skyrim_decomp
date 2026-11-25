// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x151990 MagicItem::FindEffectMatchingDefault
// Adapted bodies: none
#include "MagicItem_151990.h"

Effect* MagicItem::FindEffectMatchingDefault()
{
    for (std::uint32_t i = 0; i < effectCount; ++i) {
        Effect* effect = effects[i];
        if (effect) {
            EffectSetting* base = effect->baseEffect;
            if (base == Function14d670())
                return effects[i];
        }
    }
    return nullptr;
}
