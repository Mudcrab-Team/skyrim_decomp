// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x691cc0 Actor::IsFollowing
// Adapted bodies: none
#include "Actor_691cc0.h"

// Return whether the actor is executing an active follow package or holds a valid follow target handle.
bool Actor::IsFollowing() const
{
    if (!currentProcess) {
        return false;
    }
    const TESPackage* package = currentProcess->GetCurrentPackage();
    if (package && package->type == 1 && !package->IsInactive()) {
        return true;
    }
    BSPointerHandle handle;
    std::uint32_t   raw   = currentProcess->GetFollowTarget(handle).nativeHandle;
    std::uint32_t   index = raw & 0xfffffu;
    const HandleEntry& entry = g_handleTable[index];
    if ((entry.flags & (1u << 26)) != 0 && ((entry.flags ^ raw) & 0x3f00000u) == 0) {
        return (entry.ptr->handleRefCount >> 11) == index;
    }
    return false;
}
