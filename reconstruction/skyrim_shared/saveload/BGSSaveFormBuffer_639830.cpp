// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// BGSSaveFormBuffer::GetReference: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/SaveGame/Buffers/BGSSaveFormBuffer.cpp:65
// TESForm, BGSSaveFormBuffer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/T/TESForm.h, include/RE/B/BaseFormComponent.h, include/RE/B/BGSSaveGameBuffer.h and include/RE/B/BGSSaveFormBuffer.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x639830 BGSSaveFormBuffer::GetReference
#include "BGSSaveFormBuffer_639830.h"
const TESObjectREFR* BGSSaveFormBuffer::GetReference() { TESForm* form = GetForm(); return form ? form->AsReference2() : nullptr; }
