// Source exposure: mixed
// Origin: independently decoded target and anonymous sibling; declarations adapted from community headers.
// names: GUESS(low); names and signatures are hypotheses.
// TESLevCharacter::LoadGame, TESLevCharacter::Revert: SIBLING(fo4-private@1b765c70, author-permission); adapted behavior.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESLevCharacter.cpp:210
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESLevCharacter.cpp:217
// TESLevCharacter, TESLeveledList, TESBoundAnimObject, TESBoundObject: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/T/TESLevCharacter.h, include/RE/T/TESLeveledList.h, include/RE/T/TESBoundAnimObject.h and include/RE/T/TESBoundObject.h.
// TESForm: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/T/TESForm.h and include/RE/B/BaseFormComponent.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x271880 TESLevCharacter::LoadGame
// 0x2718c0 TESLevCharacter::Revert
#include "TESLevCharacter_271880.h"
void TESLevCharacter::LoadGame(BGSLoadFormBuffer* buffer) { TESForm::LoadGame(buffer); TESLeveledList::LoadGame(buffer); }
void TESLevCharacter::Revert(BGSLoadFormBuffer* buffer) { TESForm::Revert(buffer); TESLeveledList::Revert(buffer); }
