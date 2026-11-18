// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// BGSTalkingActivator::Revert: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/BGSTalkingActivator.cpp:168
// BGSTalkingActivator, TESObjectACTI: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/T/TESObjectACTI.h, include/RE/T/TESBoundObject.h, include/RE/T/TESForm.h and public component headers.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x267530 BGSTalkingActivator::Revert
#include "BGSTalkingActivator_267530.h"
void BGSTalkingActivator::Revert(BGSLoadFormBuffer* buffer) { TESForm::Revert(buffer); if ((unsigned char)(buffer->oldChangeFlags >> 23) & 1) tempRef = nullptr; }
