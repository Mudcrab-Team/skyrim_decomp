// TESObjectREFR: STANDIN GUESS(low); partial target-bound receiver/callee view; no full layout or ownership claim.
// Origin: original reconstruction with cited adapted declarations and complete notices.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Source exposure: mixed; Drafted by gpt-6.1-terra.
// Origin: original implementation informed by pinned community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// TESObjectREFR, TESBoundObject, BSAnimationUpdateData, GetMustUpdate, ModifyAnimationUpdateData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// DoorFlag, QueryUpdateFlag, PrepareUpdate, UnknownSlot, unknownPrefix: STANDIN GUESS(medium); predicate and output byte meanings unknown.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2fcb40 PrepareUpdate
#include "TESObjectREFR_2fcb40.h"
namespace P2073 {
BSAnimationUpdateData* TESObjectREFR::PrepareUpdate(BSAnimationUpdateData* data) {
    data->unk2A = QueryUpdateFlag();
    ModifyAnimationUpdateData(*data);
    return data;
}
}
