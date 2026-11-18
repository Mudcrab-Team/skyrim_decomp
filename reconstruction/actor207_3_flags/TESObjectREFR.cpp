// TESObjectREFR: STANDIN GUESS(low); partial target-bound receiver/callee view; no full layout or ownership claim.
// Origin: original reconstruction with cited adapted declarations and complete notices.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Source exposure: mixed; Drafted by gpt-6.1-terra.
// Origin: original implementation informed by pinned community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// TESObjectREFR, IsWater: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BaseObjectFlagView, unknownSlots, unknownPrefix, flags, FlagTwo, FlagThree: STANDIN GUESS(low); virtual placeholders represent unclaimed slots, byte meaning and base-object type unknown.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2e3f50 FlagTwo
// 0x2e3f90 FlagThree
#include "TESObjectREFR.h"
namespace P2073 {
bool TESObjectREFR::FlagTwo() { if (IsWater()) return ((baseObject->flags >> 2) & 1) != 0; return false; }
bool TESObjectREFR::FlagThree() { if (IsWater()) return ((baseObject->flags >> 3) & 1) != 0; return false; }
}
