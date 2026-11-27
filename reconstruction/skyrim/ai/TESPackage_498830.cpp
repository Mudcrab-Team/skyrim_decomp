// Source exposure: mixed (labelled community declarations and the pinned image listing).
// Code origin: original typed reconstruction; layouts retained or adapted from the labelled declaration sources.
// Adapted bodies: none
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// New function names, signatures and helper names: GUESS(low); unknown semantics remain unnamed.
// 0x498830 ReconstructedTESPackage::TESPackage::Function498830
// 0x49e730 ReconstructedTESPackage::TESPackage::Function49e730
// 0x4987e0 ReconstructedTESPackage::TESPackage::Function4987e0
// 0x4987f0 ReconstructedTESPackage::TESPackage::Function4987f0
// 0x498810 ReconstructedTESPackage::TESPackage::Function498810
#include "TESPackage_498830.h"



namespace ReconstructedTESPackage {

// Set the package owner quest.
void TESPackage::Function498830(TESQuest* a_quest)
{
    ownerQuest = a_quest;
}

// Initialize the procedure when it has no assigned type.
void TESPackage::Function49e730()
{
    constexpr std::int32_t kUninitializedProcedure = -1;
    if (procedureType == kUninitializedProcedure) {
        Function49c530();
    }
}

// Forward the operation to the corresponding package event action.
void TESPackage::Function4987e0()
{
    onBegin.Function4a23c0();
}

// Forward the operation to the corresponding package event action.
void TESPackage::Function4987f0()
{
    onEnd.Function4a23c0();
}

// Forward the operation to the corresponding package event action.
void TESPackage::Function498810()
{
    onChange.Function4a23c0();
}

}
