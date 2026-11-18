// Source exposure: mixed (community headers and pinned-image analysis).
// Code origin: original reconstruction; declarations adapted from the pinned MIT community headers.
// Drafted by gpt-6.1-sol, Engineers p105 and p115. Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x14b100 EffectSetting::ClearData
#include "EffectSetting.h"
void EffectSetting::ClearData() { auto* sounds=&effectSounds; if(sounds->data) { ClearArray(sounds); sounds->count=0; } conditions.Clear(); }

