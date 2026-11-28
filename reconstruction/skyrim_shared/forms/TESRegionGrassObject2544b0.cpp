// Source exposure: mixed (pinned image listing; CrashLogger PDB names; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: TestBit, treated as adapted: shaped like TestBit in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
// Cookbook: 0x2544b0 16
// SPDX-License-Identifier: CC0-1.0
// 0x2544b0 TESRegionGrassObject2544b0::ValidObject
#include "TESRegionGrassObject2544b0.h"

namespace
{
// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value (cookbook rule 16).
inline bool TestBit(std::uint32_t word, std::uint32_t bit)
{
    return ((word >> bit) & 1u) != 0;
}
}

// Validate a grass form for region placement and return an error bit or 0 if valid.
std::uint32_t TESRegionGrassObject2544b0::ValidObject(GrassForm2544b0* form)
{
    if (!form)
    {
        return 1;
    }
    if (TestBit(form->flags, 5))
    {
        return 2;
    }
    if (!form->model.HasModel())
    {
        return 4u;
    }
    return 0u;
}
