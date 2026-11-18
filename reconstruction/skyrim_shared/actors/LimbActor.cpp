// LimbActor: STANDIN GUESS(low); partial target-bound receiver/callee view, no complete layout or ownership asserted.
// Origin: original reconstruction; cited adapted declarations retain complete notices.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Source exposure: mixed; drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md. Prefix adapted from CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2ef760 P2071::LimbActor::IsLimbGone
#include "LimbActor.h"
namespace P2071 {
bool LimbActor::IsLimbGone(std::uint32_t limb) {
    auto* data = FindLimbData(&reference.extraList);
    if (!data) return false;
    return CheckLimb(data, limb);
}
}
