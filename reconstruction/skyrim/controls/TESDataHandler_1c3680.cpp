// Source exposure: mixed (labelled community declarations and the pinned image listing).
// Code origin: original typed reconstruction; layouts retained or adapted from the labelled declaration sources.
// Adapted bodies: none
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// New function names, signatures and helper names: GUESS(low); unknown semantics remain unnamed.
// 0x1c3680 TESDataHandler::IsTemporaryFormID
// 0x1bade0 TESDataHandler::Function1bade0
#include "TESDataHandler_1c3680.h"




// Test the created-form ID range.
bool TESDataHandler::IsTemporaryFormID(std::uint32_t a_formID)
{
    constexpr std::uint32_t kCreatedFormID = 0xFF000000u;
    return a_formID >= kCreatedFormID;
}

// Return the interior-cell array size.
std::uint16_t TESDataHandler::Function1bade0() const
{
    return interiorCells._base._size;
}
