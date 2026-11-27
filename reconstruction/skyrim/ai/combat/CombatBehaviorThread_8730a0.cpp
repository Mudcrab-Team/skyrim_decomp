// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x8730a0 CombatBehaviorThread::CheckParent
// Adapted bodies: none
#include "CombatBehaviorThread_8730a0.h"

// Return whether the given thread is an ancestor in this thread's parent chain.
bool CombatBehaviorThread::CheckParent(const CombatBehaviorThread* a_parent) const
{
    const CombatBehaviorThread* current = parent;
    while (current && current != a_parent) {
        current = current->parent;
    }
    return current == a_parent;
}
