// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x8731b0 CombatBehaviorThread::Suspend
// Adapted bodies: none
#include "CombatBehaviorThread_8731b0.h"

// Mark this behavior thread and all child threads as suspended.
void CombatBehaviorThread::Suspend()
{
    flags |= 2u;
    for (std::uint32_t i = 0; i < children.size; ++i) {
        children.Data()[i]->Suspend();
    }
}
