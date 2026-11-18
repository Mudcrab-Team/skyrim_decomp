// Source exposure: mixed (local target analysis, public declarations and permitted sibling).
// Origin: reconstructed from target and sibling hints.
// names: GUESS(low); signatures and type names are hypotheses.
// TESObjectREFR::GetCurrentBiped: SIBLING(fo4-private@1b765c70, author-permission); adapted virtual forwarding.
// TESObjectREFR::Get3D: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); body adapted from src/RE/T/TESObjectREFR.cpp:102; declaration from include/RE/T/TESObjectREFR.h.
// TESObjectREFR::MoveHavok: SIBLING(fo4-private@1b765c70, author-permission); adapted simulation reset.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectREFR.cpp:2436
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectREFR.cpp:3193
// TESObjectREFR and virtual declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2ef670 TESObjectREFR::GetCurrentBiped
// 0x2f9f40 TESObjectREFR::Get3D
// 0x2f10d0 TESObjectREFR::MoveHavok
#include "TESObjectREFR.h"
const BSTSmartPointer<BipedAnim>& TESObjectREFR::GetCurrentBiped() const { return GetBiped2(); }
NiAVObject* TESObjectREFR::Get3D() const { return Get3D2(); }
void TESObjectREFR::MoveHavok(bool force) { bhkNPCollisionObject::ResetSim(Get3D2(), force); }
