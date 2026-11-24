// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: adapted from the cited sibling body; layout and names checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/EffectItem.cpp:24
// 0x148c90 Effect::Initialize
#include "Effect_148c90.h"

void Effect::Initialize(EffectSetting* a_effect, float a_magnitude, std::uint32_t a_duration, std::uint32_t a_area)
{
    baseEffect = a_effect;
    SetCost();
    effectItem.magnitude = a_magnitude;
    effectItem.area = a_area;
    effectItem.duration = a_duration;
    SetCost();
}
