// TESObjectREFR: STANDIN GUESS(low); partial target view; original identities and ownership remain hypotheses.
// Source exposure: mixed; Drafted by gpt-6.1-terra.
// Origin: original implementation informed by pinned community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// TESObjectREFR, TESForm, ExtraDataList, extraList, formFlags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// ExtraData, GetByType, Remove, HasType, ClearExtra, HasFlagOrExtra, unknown0, unknown14, unknown48: STANDIN GUESS(medium); names and exact contracts inferred from target calls and field accesses.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
namespace P2073 {
class ExtraData;
class ExtraDataList {
public:
    ExtraData* GetByType(int type);
    void Remove(ExtraData* extra, bool freeIt);
    bool HasType(int type);
};
class TESForm {
public:
    std::uint8_t unknown0[0x10];
    std::uint32_t formFlags;
};
class TESObjectREFR {
public:
    void ClearExtra();
    bool HasFlagOrExtra();
    std::uint8_t unknown0[0x10];
    std::uint32_t formFlags;
    std::uint8_t unknown14[0x2c];
    TESForm* baseObject;
    std::uint8_t unknown48[0x28];
    ExtraDataList extraList;
};
}
