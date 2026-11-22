// Source exposure: mixed (community headers and pinned-image analysis).
// Code origin: original reconstruction; declarations adapted from the pinned MIT community headers.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x14b100 EffectSetting::ClearData
// 0x14b870 EffectSetting::Function14b870
// Adapted bodies: none
// EffectSetting::Function14b870, EffectArchetypeInfo, g_effectArchetypeInfo: GUESS(low); a per-archetype table of 0x18-byte entries whose flag bit 8 the function reads
#include "EffectSetting.h"
void EffectSetting::ClearData() { auto* sounds=&effectSounds; if(sounds->data) { ClearArray(sounds); sounds->count=0; } conditions.Clear(); }

bool EffectSetting::Function14b870() const
{
    return (g_effectArchetypeInfo[data.archetype].flags >> 8) & 1;
}
