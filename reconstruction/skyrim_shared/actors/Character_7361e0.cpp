// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x7361e0 Character::sub_1406783D0
// Adapted bodies: none
#include "Character_7361e0.h"

// Return whether the handle stored at offset 0x1f0 resolves to a live handle-table entry.
bool Character::sub_1406783D0() const
{
    std::uint32_t      raw   = unk1f0;
    std::uint32_t      index = raw & 0xfffffu;
    const HandleEntry& entry = g_handleTable[index];
    if ((entry.flags & (1u << 26)) != 0 && ((entry.flags ^ raw) & 0x3f00000u) == 0) {
        return (entry.ptr->handleRefCount >> 11) == index;
    }
    return false;
}
