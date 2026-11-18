// Source exposure: mixed
// Origin: independently decoded target and anonymous sibling; declarations adapted from community headers.
// names: GUESS(low); names and signatures are hypotheses.
// TESObjectREFR::GetFullLODRef: SIBLING(fo4-private@1b765c70, author-permission); adapted behavior.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectREFR.cpp:714
// FormType: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); names from include/RE/F/FormTypes.h.
// TESForm, TESObjectREFR: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/T/TESForm.h, include/RE/T/TESObjectREFR.h and include/RE/B/BaseFormComponent.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2e3ce0 TESObjectREFR::GetFullLODRef
#include "TESObjectREFR_2e3ce0.h"
bool TESObjectREFR::GetFullLODRef() const { const TESObjectREFR* actor = formType == 0x3e ? this : nullptr; if (actor || objectReference->formType == 0x1f) return false; return (formFlags & 0x10000u) != 0; }
