// Actor: STANDIN GUESS(low); partial target-bound receiver/callee view; no full layout or ownership claim.
// Origin: original reconstruction with cited adapted declarations and complete notices.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Source exposure: mixed; Drafted by gpt-6.1-terra.
// Origin: original implementation informed by pinned community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Actor, ExtraDataList: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// ExtraData, GetByType, Update, UpdateExtra, unknownPrefix: STANDIN GUESS(medium); callee meaning and extra subtype remain unknown.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
namespace P2073 {
class ExtraData { public: void Update(bool); };
class ExtraDataList { public: ExtraData* GetByType(std::int32_t); };
class Actor {
public:
    void UpdateExtra(bool value);
    std::uint8_t unknownPrefix[0x70];
    ExtraDataList extraList;
};
}
