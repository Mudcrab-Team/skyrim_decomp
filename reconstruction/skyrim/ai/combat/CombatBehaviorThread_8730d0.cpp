// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x8730d0 CombatBehaviorThread::CheckRelated
// Adapted bodies: none
#include "CombatBehaviorThread_8730d0.h"

// Return whether two behavior threads are identical or related by ancestry.
bool CombatBehaviorThread::CheckRelated(const CombatBehaviorThread* a_other) const
{
    return a_other == this || CheckParent(a_other) || a_other->CheckParent(this);
}
