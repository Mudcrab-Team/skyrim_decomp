// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: MultiTargetCtrl221a90::ClearTargetsRecursive, treated as adapted: shaped like a recursive scene node walk in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00480000_o2.cpp:4668
// SPDX-License-Identifier: CC0-1.0
// NiNode221a90, NiAVObject221a90, MultiTargetCtrl221a90, AsNode, GetTargetIndex, ClearTargetsRecursive, children, childCount, targets, numInterps, kInvalidIndex221a90: GUESS(low)
#pragma once

#include <cstdint>

extern const std::uint16_t kInvalidIndex221a90;

class NiNode221a90;

class NiAVObject221a90
{
public:
    virtual ~NiAVObject221a90();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual NiNode221a90* AsNode();

    std::uint8_t unk08[0x110];  // 008
};

class NiNode221a90 : public NiAVObject221a90
{
public:
    NiAVObject221a90** children;  // 118
    std::uint16_t maxSize;        // 120
    std::uint16_t childCount;     // 122
};

class MultiTargetCtrl221a90
{
public:
    std::uint16_t GetTargetIndex(NiAVObject221a90* obj) const
    {
        if (obj)
        {
            for (std::uint16_t i = 0; i < numInterps; ++i)
            {
                if (targets[i] == obj)
                {
                    return i;
                }
            }
        }
        return kInvalidIndex221a90;
    }

    void ClearTargetsRecursive(NiAVObject221a90* obj);

    std::uint8_t unk00[0x50];     // 00
    NiAVObject221a90** targets;   // 50
    std::uint16_t numInterps;     // 58
};
