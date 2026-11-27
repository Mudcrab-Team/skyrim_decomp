// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original compact projection of community layout
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESBoundObject, TESBoundObject::BOUND_DATA, TESBoundObject::BOUND_DATA::boundMin, TESBoundObject::BOUND_DATA::boundMax, TESBoundObject::boundData, NiNPShortPoint3, NiNPShortPoint3::x, NiNPShortPoint3::y, NiNPShortPoint3::z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiNPShortPoint3::NiNPShortPoint3: GUESS(low); ordinary coordinate constructor
// TESBoundObject::Function277a80: GUESS(low); neutral RVA name
// TESBoundObject::prefix: GUESS(low) STANDIN; unaccessed base storage
#pragma once
#include <cstdint>
#include <cstddef>
struct NiNPShortPoint3 {
    NiNPShortPoint3(int16_t xValue, int16_t yValue, int16_t zValue) : x(xValue), y(yValue), z(zValue) {}
    int16_t x, y, z;
};
class TESBoundObject {
public:
    struct BOUND_DATA { NiNPShortPoint3 boundMin, boundMax; };
    float Function277a80();
    uint8_t prefix[0x20];
    BOUND_DATA boundData;
};
static_assert(offsetof(TESBoundObject, boundData) == 0x20, "bound data offset");
static_assert(offsetof(TESBoundObject::BOUND_DATA, boundMax) == 6, "maximum bound offset");
