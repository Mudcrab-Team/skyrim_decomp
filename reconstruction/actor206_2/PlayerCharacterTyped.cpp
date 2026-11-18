// Source exposure: mixed.
// Origin: Original reconstruction informed by target access witnesses and community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// PlayerCharacterTyped: STANDIN GUESS(low); receiver identity is provisional.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x677c40 P2062::PlayerCharacter::Function677c40
// 0x6adea0 P2062::PlayerCharacter::Function6adea0

#include "PlayerCharacterTyped.h"
namespace P2062 {
bool PlayerCharacterTyped::Function677c40() { return currentProcess && currentProcess->QueryOne(); }
bool PlayerCharacterTyped::Function6adea0() { return currentProcess && currentProcess->QueryTwo(); }
}
