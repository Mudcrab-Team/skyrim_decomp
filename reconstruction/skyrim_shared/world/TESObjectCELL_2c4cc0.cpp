// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: handwritten reconstruction with permitted sibling control-flow guidance.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2c4cc0 TESObjectCELL::SetAltered
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesobjectcell.cpp:1628
// Adapted bodies: TESObjectCELL::SetAltered, momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesobjectcell.cpp:1628, CC0-1.0; base call and parent propagation guidance.
// TestBit: GUESS(low); flag-index helper following cookbook rule 16.
#include "TESObjectCELL_2c4cc0.h"

inline bool TestBit(std::uint32_t flags, std::uint32_t bit)
{
    return ((flags >> bit) & 1) != 0;
}

void TESObjectCELL::SetAltered(bool set)
{
    TESForm::SetAltered(set);
    if (!TestBit(formFlags, 14) && TestBit(formFlags, 1) &&
        !(cellFlags & 1) && worldSpace) {
        worldSpace->SetAltered(true);
    }
}
