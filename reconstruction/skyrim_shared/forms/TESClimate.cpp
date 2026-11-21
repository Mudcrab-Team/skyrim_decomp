// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original; the listing and community declarations only
// 0x2a5c10 TESClimate::InitializeData
// Adapted bodies: none
#include "TESClimate.h"

void TESClimate::InitializeData()
{
    timing = Timing();
    timing.moonPhaseLength = 3;
}
