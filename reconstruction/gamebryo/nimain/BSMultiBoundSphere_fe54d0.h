// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (community declarations; the pinned image listing).
// Code origin: original; the listing and community names only
// BSMultiBoundSphere: EXE_RTTI
// GetType: GUESS(low); a virtual that gives the class its vptr, named for the slot the generated unit of this class uses
// NiPoint3: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); partial view of the center
// BSMultiBoundSphere::center, BSMultiBoundSphere::radius: GUESS(low); the center and radius members at the offsets the image uses
// every member named unknownNN: GUESS(low); the compared bodies read none of them
#pragma once

#include <cstdint>

struct NiPoint3
{
    float x;  // 0
    float y;  // 4
    float z;  // 8
};
static_assert(sizeof(NiPoint3) == 0xc, "NiPoint3 size");

class BSMultiBoundSphere
{
public:
    virtual std::uint32_t GetType() const;
    void Functionfe54d0(const NiPoint3& a_center);

    std::uint64_t unknown08;  // 08
    std::uint64_t unknown10;  // 10
    NiPoint3 center;  // 18
    float radius;  // 24
};
static_assert(sizeof(BSMultiBoundSphere) == 0x28, "size");
