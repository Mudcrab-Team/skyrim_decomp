// Source exposure: mixed
// Origin: independently decoded target and anonymous sibling; declarations adapted from community headers.
// names: GUESS(low); names and signatures are hypotheses.
// TESObjectREFR::GetIgnoredBySandbox, TESObjectREFR::SetObjectReference: SIBLING(fo4-private@1b765c70, author-permission); adapted behavior.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectREFR.cpp:3521
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectREFR.cpp:2500
// TESForm, TESObjectREFR: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/T/TESForm.h, include/RE/T/TESObjectREFR.h and include/RE/B/BaseFormComponent.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2e48c0 TESObjectREFR::GetIgnoredBySandbox
// 0x2f0c00 TESObjectREFR::SetObjectReference
#include "TESObjectREFR.h"
bool TESObjectREFR::GetIgnoredBySandbox() const { if (data.objectReference->GetIgnoredBySandbox()) return true; if (extraList.GetIgnoredBySandbox()) return true; return false; }
void TESObjectREFR::SetObjectReference(TESBoundObject* object) { data.objectReference = object; SetDestructible(BGSDestructibleObjectForm::IsDestructible(object)); }
