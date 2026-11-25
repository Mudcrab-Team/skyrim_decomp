// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x5ba2d0 AccumulatingValueModifierEffect::SaveGame
// Adapted bodies: AccumulatingValueModifierEffect::SaveGame follows fo4-private@1b765c70 src/Game/Magic/AccumulatingValueModifierEffect.cpp
// Sibling source: fo4-private@1b765c70 src/Game/Magic/AccumulatingValueModifierEffect.cpp:38
#include "AccumulatingValueModifierEffect_5ba2d0.h"

// Writes the three accumulated values after the base effect state.
void AccumulatingValueModifierEffect::SaveGame(BGSSaveFormBuffer* a_buf)
{
    ActiveEffect::SaveGame(a_buf);
    a_buf->SaveDataEndian(&accumulatedMagnitude, 4, 4, 0);
    a_buf->SaveDataEndian(&maximumMagnitude, 4, 4, 0);
    a_buf->SaveDataEndian(&holdTimer, 4, 4, 0);
}
