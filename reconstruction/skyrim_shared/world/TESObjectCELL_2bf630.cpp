// Source exposure: mixed (community declarations and pinned-image observations).
// Code origin: original handwritten reconstruction
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
// 0x2bf630 TESObjectCELL::Function2bf630
#include "TESObjectCELL_2bf630.h"

void TESObjectCELL::Function2bf630(bool enabled)
{
    if (enabled)
        cellFlags |= 0x200;
    else
        cellFlags &= ~0x200;
    AddChange(2);
}
