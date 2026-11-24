// Source exposure: mixed (pinned image and public declarations).
// Code origin: original partial layout of the axis-aligned bound.
// BSMultiBoundAABB, BSMultiBoundShape, NiPoint3, x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CopyShapeMembers, halfExtents: GUESS(low)
// BSMultiBoundAABB::CopyMembers: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(tesv-2013-map)
#pragma once

#include "BSMultiBoundShape.h"
class NiPoint3
{
public:
    float x;
    float y;
    float z;
};

class BSMultiBoundAABB : public BSMultiBoundShape
{
public:
    void CopyMembers(BSMultiBoundAABB* target) const;

private:
    std::uint32_t unknown18;
    NiPoint3 center;
    std::uint32_t unknown28;
    NiPoint3 halfExtents;
    std::uint8_t unknown38[8];
};

static_assert(sizeof(BSMultiBoundAABB) == 0x40, "axis-aligned bound size");
