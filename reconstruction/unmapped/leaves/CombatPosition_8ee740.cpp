// Source exposure: mixed (sibling source; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x8ee740 CombatPosition::LoadGame
// Adapted bodies: CombatPosition::LoadGame from the sibling source named in the header
#include "CombatPosition_8ee740.h"

void CombatPosition::LoadGame(BGSLoadGameBuffer* a_buffer)
{
    a_buffer->LoadDataEndian(this, sizeof(location), sizeof(float));
    a_buffer->LoadDataEndian(&fRadius, sizeof(fRadius), sizeof(fRadius));
}
