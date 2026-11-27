// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x873070 CombatBehaviorThread::GetAscendingUpdate
// Adapted bodies: none
#include "CombatBehaviorThread_873070.h"

// Return whether the current node is the parent of the previous node.
bool CombatBehaviorThread::GetAscendingUpdate() const
{
    return currentNode && previousNode && currentNode == previousNode->parent;
}
