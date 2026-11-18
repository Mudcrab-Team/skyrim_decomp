// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// BGSAttackDataForm::ClearDataComponent: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/BGSAttackDataForm.cpp:21
// BGSAttackDataForm, NiRefObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/B/BGSAttackDataForm.h, include/RE/B/BGSAttackDataMap.h, include/RE/N/NiRefObject.h and include/RE/N/NiSmartPointer.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1d1a80 BGSAttackDataForm::ClearDataComponent
#include "BGSAttackDataForm_1d1a80.h"
void BGSAttackDataForm::ClearDataComponent() { BGSAttackDataMap* old = attackDataMap; if (old) { attackDataMap = nullptr; if (old->refCount.fetch_sub(1) == 1) old->DeleteThis(); } }
