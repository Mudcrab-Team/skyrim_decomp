// Source exposure: mixed
// Origin: independently decoded target and anonymous sibling; declarations adapted from community headers.
// names: GUESS(low); names and signatures are hypotheses.
// TESForm::SetDelete: SIBLING(fo4-private@1b765c70, author-permission); adapted behavior.
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESForm.cpp:372
// TESForm: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/T/TESForm.h and include/RE/B/BaseFormComponent.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1e6070 TESForm::SetDelete
#include "TESForm_1e6070.h"
void TESForm::SetDelete(bool value) { unsigned flags = formFlags; if ((bool)((flags >> 5) & 1) != value) { formFlags = value ? (flags | 0x20u) : (flags & ~0x20u); AddChange(1); } }
