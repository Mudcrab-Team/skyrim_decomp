// Source exposure: mixed
// Origin: independently decoded target and anonymous sibling; declarations adapted from community headers.
// names: GUESS(low); names and signatures are hypotheses.
// TESObjectREFR::GetDangerous: SIBLING(fo4-private@1b765c70, author-permission); adapted behavior.
// TESObjectREFR::GetRandomAnim: SIBLING(fo4-private@1b765c70, author-permission); adapted behavior.
// TESObjectREFR::GetObstacle: SIBLING(fo4-private@1b765c70, author-permission); adapted behavior.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectREFR.cpp:160
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectREFR.cpp:1378
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectREFR.cpp:772
// TESForm, TESObjectREFR: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/T/TESForm.h, include/RE/T/TESObjectREFR.h and include/RE/B/BaseFormComponent.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2e3da0 TESObjectREFR::GetDangerous
// 0x2ee6b0 TESObjectREFR::GetRandomAnim
// 0x2e3dc0 TESObjectREFR::GetObstacle
#include "TESObjectREFR.h"
bool TESObjectREFR::GetDangerous() const { return objectReference->GetDangerous(); }
bool TESObjectREFR::GetRandomAnim() const { return objectReference->GetRandomAnim(); }
bool TESObjectREFR::GetObstacle() const { return objectReference && objectReference->GetObstacle(); }
