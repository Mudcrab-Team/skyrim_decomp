// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: NiTArray220f10::RemoveEnd, treated as adapted: shaped like NiTArray::RemoveEnd in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/niparticle/nimeshpsysdata.cpp:1292
// SPDX-License-Identifier: CC0-1.0
// 0x220f10 ArrayOwner220f10::~ArrayOwner220f10
#include "ArrayOwner220f10.h"

// Delete all remaining items in the array before releasing its storage.
ArrayOwner220f10::~ArrayOwner220f10()
{
    std::uint16_t count = items.firstFreeIdx;
    for (std::uint16_t i = 0; i < count; ++i)
    {
        delete items.RemoveEnd();
    }
}
