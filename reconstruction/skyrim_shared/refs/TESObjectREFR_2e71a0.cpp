// Source exposure: mixed
// Origin: independently decoded target and anonymous sibling; declarations adapted from community headers.
// names: GUESS(low); names and signatures are hypotheses.
// TESObjectREFR::GetStartingAngle, TESObjectREFR::GetStartingLocation: SIBLING(fo4-private@1b765c70, author-permission); adapted behavior.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectREFR.cpp:2191
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectREFR.cpp:2197
// TESForm, TESObjectREFR: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/T/TESForm.h, include/RE/T/TESObjectREFR.h and include/RE/B/BaseFormComponent.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2e71a0 TESObjectREFR::GetStartingAngle
// 0x2e71d0 TESObjectREFR::GetStartingLocation
#include "TESObjectREFR_2e71a0.h"
NiPoint3 TESObjectREFR::GetStartingAngle() const { return extraList.GetStartingAngle(this); }
NiPoint3 TESObjectREFR::GetStartingLocation() const { return extraList.GetStartingLocation(this); }
