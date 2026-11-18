// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// BGSConstructibleObject::InitializeData: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/BGSConstructibleObject.cpp:109
// BGSConstructibleObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/B/BGSConstructibleObject.h, include/RE/T/TESForm.h, include/RE/T/TESContainer.h and include/RE/T/TESCondition.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x25de70 BGSConstructibleObject::InitializeData
#include "BGSConstructibleObject.h"
void BGSConstructibleObject::InitializeData() { createdItem = nullptr; benchKeyword = nullptr; requiredItems.InitializeDataComponent(); }
