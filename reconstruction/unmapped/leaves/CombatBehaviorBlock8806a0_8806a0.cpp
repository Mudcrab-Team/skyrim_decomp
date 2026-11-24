// Source exposure: mixed (sibling source; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x8806a0 CombatBehaviorBlock8806a0::SaveGame
// Adapted bodies: CombatBehaviorBlock8806a0::SaveGame from the sibling source named in the header
#include "CombatBehaviorBlock8806a0_8806a0.h"

void CombatBehaviorBlock8806a0::SaveGame(BGSSaveFormBuffer* a_buffer) const
{
    BlockTimer.SaveGame(a_buffer);
    BashTimer.SaveGame(a_buffer);
    CheckDistanceTimer.SaveGame(a_buffer);
}
