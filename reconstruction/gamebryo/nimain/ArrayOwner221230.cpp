// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: NiTArray221230::RemoveEnd, treated as adapted: shaped like NiTArray::RemoveEnd in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/niparticle/nimeshpsysdata.cpp:1292
// SPDX-License-Identifier: CC0-1.0
// 0x221230 ArrayOwner221230::ClearItems
#include "ArrayOwner221230.h"

// Delete all items in the array and return true if any existed.
bool ArrayOwner221230::ClearItems()
{
    bool cleared = false;
    std::uint16_t count = items.firstFreeIdx;
    for (std::uint16_t i = 0; i < count; ++i)
    {
        delete items.RemoveEnd();
        cleared = true;
    }
    return cleared;
}
