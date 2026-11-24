// Source exposure: mixed (labelled community declarations and the pinned image listing).
// Code origin: original typed reconstruction; layouts retained or adapted from the labelled declaration sources.
// Adapted bodies: none
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// New function names, signatures and helper names: GUESS(low); unknown semantics remain unnamed.
// 0x3f2e60 ReconstructedTESTopicInfo::TESTopicInfo::Function3f2e60
#include "TESTopicInfo_3f2e60.h"



namespace ReconstructedTESTopicInfo {

// Clear the said-once state and its change flag.
void TESTopicInfo::Function3f2e60()
{
    constexpr std::uint32_t kSaidOnceChange = 0x80000000u;
    saidOnce = false;
    RemoveChange(kSaidOnceChange);
}

}
