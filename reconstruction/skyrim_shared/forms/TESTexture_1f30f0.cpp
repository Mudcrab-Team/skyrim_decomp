// Source exposure: mixed (labelled community declarations and the pinned image listing).
// Code origin: original typed reconstruction; layouts retained or adapted from the labelled declaration sources.
// Adapted bodies: none
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// New function names, signatures and helper names: GUESS(low); unknown semantics remain unnamed.
// 0x1f30f0 ReconstructedTESTexture::TESTexture::Function1f30f0
#include "TESTexture_1f30f0.h"



namespace ReconstructedTESTexture {

// Recognize the ICON record tag.
bool TESTexture::Function1f30f0(std::uint32_t a_record)
{
    constexpr std::uint32_t kIconRecord = 0x4E4F4349u;
    return a_record == kIconRecord;
}

}
