// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x873530 CombatBehaviorThread::SetAborted
// Adapted bodies: none
#include "CombatBehaviorThread_873530.h"

// Mark this behavior thread and all child threads as aborted.
void CombatBehaviorThread::SetAborted()
{
    state = 2;
    for (std::uint32_t i = 0; i < children.size; ++i) {
        children.Data()[i]->SetAborted();
    }
}
