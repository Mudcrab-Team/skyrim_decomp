// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: minimal community declarations with opaque unaccessed storage.
// ExtraWaterCurrentZoneData, BSExtraData, NiPoint3, angularVelocity, linearVelocity, x, y, z, IsNotEqual: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSExtraData, NiPoint3: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once
#include <cstddef>

class BSExtraData;
struct NiPoint3 { float x, y, z; };
class ExtraWaterCurrentZoneData {
public:
    // 0x18c4d0 ExtraWaterCurrentZoneData::IsNotEqual
    bool IsNotEqual(const BSExtraData* rhs) const;
    unsigned char _pad00[0x50];
    NiPoint3 angularVelocity; // 0x50
    NiPoint3 linearVelocity; // 0x5c
};
static_assert(offsetof(ExtraWaterCurrentZoneData, angularVelocity) == 0x50, "angularVelocity offset");
static_assert(offsetof(ExtraWaterCurrentZoneData, linearVelocity) == 0x5c, "linearVelocity offset");
