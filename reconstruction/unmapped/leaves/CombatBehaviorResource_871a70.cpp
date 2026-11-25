// Source exposure: mixed (sibling source; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x871a70 CombatBehaviorResource::SetOwner
// Adapted bodies: CombatBehaviorResource::SetOwner from the sibling source named in the header
#include "CombatBehaviorResource_871a70.h"

void CombatBehaviorResource::SetOwner(CombatBehaviorThread* a_thread)
{
    if (!pOwner || !a_thread->CheckParent(pOwner)) {
        pOwner = a_thread;
    }
}
