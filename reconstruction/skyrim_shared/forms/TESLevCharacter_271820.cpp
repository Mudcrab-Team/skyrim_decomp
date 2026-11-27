// Source exposure: mixed (labelled community declarations and the pinned image listing).
// Code origin: original typed reconstruction; layouts retained or adapted from the labelled declaration sources.
// Adapted bodies: none
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// New function names, signatures and helper names: GUESS(low); unknown semantics remain unnamed.
// 0x271820 ReconstructedTESLevCharacter::TESLevCharacter::Function271820
// 0x271830 ReconstructedTESLevCharacter::TESLevCharacter::Function271830
#include "TESLevCharacter_271820.h"



namespace ReconstructedTESLevCharacter {

// Read the unidentified leveled-character state word.
std::uint32_t TESLevCharacter::Function271820()
{
    return unknownLeveledCharacterState207acc0;
}

// Accept the two adjacent character form types.
bool TESLevCharacter::Function271830(std::uint8_t a_type)
{
    constexpr std::uint8_t kFirstCharacterType = 0x2B;
    return static_cast<std::uint8_t>(a_type - kFirstCharacterType) <= 1;
}

}
