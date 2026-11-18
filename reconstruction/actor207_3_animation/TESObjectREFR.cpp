// TESObjectREFR: STANDIN GUESS(low); partial target-bound receiver/callee view; no full layout or ownership claim.
// Origin: original reconstruction with cited adapted declarations and complete notices.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Source exposure: mixed; Drafted by gpt-6.1-terra.
// Origin: original implementation informed by pinned community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// TESObjectREFR, IAnimationGraphManagerHolder, BSFixedString, GetGraphVariableImpl2, GetGraphVariableImpl3: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// AnimationNames, GetAnimationNames, sprintName, syncName, IsSprinting, HasSyncSprint, unknownPrefix: STANDIN GUESS(medium); names and variable identity inferred; unaccessed slots unknown.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x6af090 IsSprinting
// 0x6aec50 HasSyncSprint
#include "TESObjectREFR.h"
namespace P2073 {
bool TESObjectREFR::IsSprinting() {
    bool value = false;
    AnimationNames* names = GetAnimationNames();
    graph.GetGraphVariableImpl3(names->sprintName, value);
    return value;
}
bool TESObjectREFR::HasSyncSprint() {
    std::int32_t value = 0;
    AnimationNames* names = GetAnimationNames();
    graph.GetGraphVariableImpl2(names->syncName, value);
    return value > 0;
}
}
