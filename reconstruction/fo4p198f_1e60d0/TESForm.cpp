// Source exposure: mixed
// Origin: authorized sibling and community declarations
// TESForm::SetAltered: SIBLING(fo4-private@1b765c70, author-permission); adapted using target evidence
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESForm.cpp:473
// TESForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/T/TESForm.h
// names: GUESS(low); scoped context and signature are provisional
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1e60d0 TESForm::SetAltered
#include "TESForm.h"
void TESForm::SetAltered(bool altered) {
    MemoryScope scope;
    if (altered) formFlags |= 2;
    else formFlags &= ~2u;
}
