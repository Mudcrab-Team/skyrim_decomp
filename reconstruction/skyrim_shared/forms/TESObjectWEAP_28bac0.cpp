// Source exposure: mixed (labelled community declarations and the pinned image listing).
// Code origin: original typed reconstruction; layouts retained or adapted from the labelled declaration sources.
// Adapted bodies: none
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// New function names, signatures and helper names: GUESS(low); unknown semantics remain unnamed.
// 0x28bac0 ReconstructedTESObjectWEAP::TESObjectWEAP::Function28bac0
// 0x28c240 ReconstructedTESObjectWEAP::TESObjectWEAP::Function28c240
#include "TESObjectWEAP_28bac0.h"


namespace ReconstructedTESObjectWEAP {

// These callee names come from the pack's community reference names; signatures remain inferred.
class BGSDefaultObjectManager { public: static TESForm* GetDefaultObject(std::uint32_t a_object); };
namespace AIFormulas { float GetSoundLevelValue(std::uint32_t a_level); }

// Return the selected default object.
TESForm* TESObjectWEAP::Function28bac0()
{
    constexpr std::uint32_t kDefaultObject = 0xC4;
    return BGSDefaultObjectManager::GetDefaultObject(kDefaultObject);
}

// Convert the weapon sound level to its scalar value.
float TESObjectWEAP::Function28c240() const
{
    return AIFormulas::GetSoundLevelValue(soundLevel);
}

}
