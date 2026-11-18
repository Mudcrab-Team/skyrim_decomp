// Source exposure: mixed
// Origin: independently decoded target and anonymous sibling; declarations adapted from community headers.
// names: GUESS(low); names and signatures are hypotheses.
// BGSNote::LoadGame, BGSNote::Revert: SIBLING(fo4-private@1b765c70, author-permission); adapted behavior.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Character/BGSNote.cpp:253
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Character/BGSNote.cpp:261
// BGSLoadFormBuffer, BGSLoadFormData, BGSLoadGameBuffer: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/B/BGSLoadFormBuffer.h, include/RE/B/BGSLoadFormData.h and include/RE/B/BGSLoadGameBuffer.h.
// BGSNote, TESBoundObject, TESModel, TESFullName, TESIcon, BGSPickupPutdownSounds: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/B/BGSNote.h, include/RE/T/TESBoundObject.h, include/RE/T/TESModel.h, include/RE/T/TESFullName.h, include/RE/T/TESIcon.h and include/RE/B/BGSPickupPutdownSounds.h.
// TESForm: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/T/TESForm.h and include/RE/B/BaseFormComponent.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x3952b0 BGSNote::LoadGame
// 0x3952f0 BGSNote::Revert
#include "BGSNote.h"
void BGSNote::LoadGame(BGSLoadFormBuffer* buffer) { TESForm::LoadGame(buffer); if (buffer->changeFlags & 0x80000000u) hasBeenRead = true; }
void BGSNote::Revert(BGSLoadFormBuffer* buffer) { TESForm::Revert(buffer); if (buffer->oldChangeFlags & 0x80000000u) hasBeenRead = false; }
