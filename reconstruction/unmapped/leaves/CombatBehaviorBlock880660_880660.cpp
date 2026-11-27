// Source exposure: mixed (sibling source; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x880660 CombatBehaviorBlock880660::SaveGame
// Adapted bodies: CombatBehaviorBlock880660::SaveGame from the sibling source named in the header
#include "CombatBehaviorBlock880660_880660.h"

void CombatBehaviorBlock880660::SaveGame(BGSSaveFormBuffer* a_buffer) const
{
    BlockTimer.SaveGame(a_buffer);
    BashTimer.SaveGame(a_buffer);
    CheckDistanceTimer.SaveGame(a_buffer);
}
