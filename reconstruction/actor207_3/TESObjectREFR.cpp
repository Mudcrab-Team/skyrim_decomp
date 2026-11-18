// TESObjectREFR: STANDIN GUESS(low); partial target view; original identities and ownership remain hypotheses.
// Source exposure: mixed; Drafted by gpt-6.1-terra.
// Origin: original implementation informed by pinned community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// TESObjectREFR, TESForm, ExtraDataList, extraList, formFlags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// ExtraData, GetByType, Remove, HasType, ClearExtra, HasFlagOrExtra, unknown0, unknown14, unknown48: STANDIN GUESS(medium); names and exact contracts inferred from target calls and field accesses.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2f68c0 ClearExtra
#include "TESObjectREFR.h"
namespace P2073 {
void TESObjectREFR::ClearExtra() {
    ExtraData* extra = extraList.GetByType(0xb4);
    if (extra) extraList.Remove(extra, true);
}
}
