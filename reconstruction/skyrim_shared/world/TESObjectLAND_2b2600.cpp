// Source exposure: mixed (labelled community declarations and the pinned image listing).
// Code origin: original typed reconstruction; layouts retained or adapted from the labelled declaration sources.
// Adapted bodies: none
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// New function names, signatures and helper names: GUESS(low); unknown semantics remain unnamed.
// 0x2b2600 ReconstructedTESObjectLAND::TESObjectLAND::Function2b2600
// 0x2b6530 ReconstructedTESObjectLAND::TESObjectLAND::GetSaveParentCell
#include "TESObjectLAND_2b2600.h"


namespace ReconstructedTESObjectLAND {

// TestLandFlag: GUESS(low); the observed bit test uses the low flag byte.
inline bool TestLandFlag(std::uint8_t a_flags, unsigned a_bit)
{ return (static_cast<std::uint8_t>(a_flags >> a_bit) & 1) != 0; }

// Test the fourth land-data flag.
bool TESObjectLAND::Function2b2600() const
{
    return TestLandFlag(static_cast<std::uint8_t>(data), 3);
}

// Return the parent cell through the child-cell interface.
TESObjectCELL* TESObjectLAND::GetSaveParentCell()
{
    return parentCell;
}

}
