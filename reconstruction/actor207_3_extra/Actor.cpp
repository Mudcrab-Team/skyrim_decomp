// Actor: STANDIN GUESS(low); partial target-bound receiver/callee view; no full layout or ownership claim.
// Origin: original reconstruction with cited adapted declarations and complete notices.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Source exposure: mixed; Drafted by gpt-6.1-terra.
// Origin: original implementation informed by pinned community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Actor, ExtraDataList: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// ExtraData, GetByType, Update, UpdateExtra, unknownPrefix: STANDIN GUESS(medium); callee meaning and extra subtype remain unknown.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x6ac9c0 UpdateExtra
#include "Actor.h"
namespace P2073 {
void Actor::UpdateExtra(bool value) {
    ExtraData* extra = extraList.GetByType(0x98);
    if (extra) extra->Update(value);
}
}
