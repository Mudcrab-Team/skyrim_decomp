// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// BGSSoundOutput::InitItemImpl: SIBLING(fo4-private@1b765c70, author-permission); target behavior independently adapted.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSSoundOutput.cpp:34
// TESForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declaration adapted from include/RE/T/TESForm.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x32b510 BGSSoundOutput::InitItemImpl
#include "BGSSoundOutput.h"
void BGSSoundOutput::InitItemImpl() { if (!((unsigned char)(formFlags >> 3) & 1)) SetInitialized(true); }
