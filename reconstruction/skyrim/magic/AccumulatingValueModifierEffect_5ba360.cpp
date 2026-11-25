// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x5ba360 AccumulatingValueModifierEffect::LoadGame
// Adapted bodies: AccumulatingValueModifierEffect::LoadGame follows fo4-private@1b765c70 src/Game/Magic/AccumulatingValueModifierEffect.cpp
// Sibling source: fo4-private@1b765c70 src/Game/Magic/AccumulatingValueModifierEffect.cpp:47
#include "AccumulatingValueModifierEffect_5ba360.h"

// Reads the three accumulated values back after the base effect state.
void AccumulatingValueModifierEffect::LoadGame(BGSLoadFormBuffer* a_buf)
{
    ActiveEffect::LoadGame(a_buf);
    a_buf->LoadDataEndian(&accumulatedMagnitude, 4, 4);
    a_buf->LoadDataEndian(&maximumMagnitude, 4, 4);
    a_buf->LoadDataEndian(&holdTimer, 4, 4);
}
