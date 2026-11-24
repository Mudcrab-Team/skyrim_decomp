// Source exposure: mixed (labelled community declarations and the pinned image listing).
// Code origin: original typed reconstruction; layouts retained or adapted from the labelled declaration sources.
// Adapted bodies: none
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// New function names, signatures and helper names: GUESS(low); unknown semantics remain unnamed.
// 0x3e82c0 ReconstructedTESRace::TESRace::Function3e82c0
#include "TESRace_3e82c0.h"



namespace ReconstructedTESRace {

// Test the indexed equipment category.
bool TESRace::Function3e82c0(std::uint32_t a_index) const
{
    return (validEquipTypes & (std::uint32_t{1} << a_index)) != 0;
}

}
