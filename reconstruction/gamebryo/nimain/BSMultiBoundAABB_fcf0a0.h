// Source exposure: mixed (community declarations and the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSMultiBoundAABB: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPoint3, NiPoint3::x, NiPoint3::y, NiPoint3::z: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// center, size: CRASHLOGGER_PDB(59818@2026.10.24)
// BSMultiBoundAABB::IsInsideFrustumPlanes, BSMultiBoundPlanes, Plane, normal, distance, planes, mask, unk00, unk28: GUESS(low)
#pragma once

#include <cstdint>

struct NiPoint3
{
    float x;
    float y;
    float z;

};

struct BSMultiBoundPlanes
{
    struct Plane
    {
        NiPoint3 normal;
        float distance;
    };

    Plane planes[6];
    std::uint32_t mask;
};

class BSMultiBoundAABB
{
public:
    bool IsInsideFrustumPlanes(const BSMultiBoundPlanes& a_planes) const;

    std::uint8_t unk00[0x1C];
    NiPoint3 center;
    std::uint8_t unk28[4];
    NiPoint3 size;
};
