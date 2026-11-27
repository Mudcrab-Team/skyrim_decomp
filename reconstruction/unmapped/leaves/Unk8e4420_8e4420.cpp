// Recipe: reconstruction/recipes/o2-fpfast.json
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk8e4420: STANDIN GUESS(low)
// Unk8e4420::Function8e4420: GUESS(low)
// Unk8e4420::state, Unk8e4420::aboveThreshold, Unk8e4420::flagA, Unk8e4420::flagB, EffectState8e4420, Owner8e4420, gThreshold8e4420: GUESS(low)
// 0x8e4420 Unk8e4420::Function8e4420
#include "Unk8e4420_8e4420.h"

// Cache the referenced state and its selected properties.
void Unk8e4420::Function8e4420(const Owner8e4420& owner)
{
    state = owner.state;
    aboveThreshold = gThreshold8e4420 < state->distance;
    flagA = (state->flags >> 4) & 1;
    flagB = (state->flags >> 5) & 1;
}
