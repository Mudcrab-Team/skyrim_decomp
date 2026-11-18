// TESObjectREFR: STANDIN GUESS(low); partial target-bound receiver/callee view; no full layout or ownership claim.
// Origin: original reconstruction with cited adapted declarations and complete notices.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Source exposure: mixed; Drafted by gpt-6.1-terra.
// Origin: original implementation informed by pinned community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// TESObjectREFR, TESBoundObject, BSAnimationUpdateData, GetMustUpdate, ModifyAnimationUpdateData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// DoorFlag, QueryUpdateFlag, PrepareUpdate, UnknownSlot, unknownPrefix: STANDIN GUESS(medium); predicate and output byte meanings unknown.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2eeb00 QueryUpdateFlag
#include "TESObjectREFR_2eeb00.h"
namespace P2073 {
bool TESObjectREFR::QueryUpdateFlag() {
    if (GetMustUpdate()) return true;
    if (baseObject->formType == 0x1d) return baseObject->DoorFlag();
    return false;
}
}
