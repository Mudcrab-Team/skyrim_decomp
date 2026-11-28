// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// RegionObjNode257d50, RegionObjList257d50, RegionObj257d50, UpdateChildren, ClampToParent, SetMaximumSlope, item, next, head, minSlope, maxSlope, childrenList, parent: GUESS(low)
#pragma once

#include <cstdint>

class RegionObj257d50;

struct RegionObjNode257d50
{
    RegionObj257d50* item;      // 00
    RegionObjNode257d50* next;  // 08
};

struct RegionObjList257d50
{
    std::uint64_t unk00;       // 00
    RegionObjNode257d50 head;  // 08
};

class RegionObj257d50
{
public:
    void UpdateChildren();

    void ClampToParent()
    {
        if (parent)
        {
            if (minSlope < parent->minSlope)
            {
                minSlope = parent->minSlope;
            }
            if (maxSlope > parent->maxSlope)
            {
                maxSlope = parent->maxSlope;
            }
        }
    }

    bool SetMaximumSlope(std::uint8_t value);

    std::uint8_t unk00[0x15];          // 00
    std::uint8_t minSlope;             // 15
    std::uint8_t maxSlope;             // 16
    std::uint8_t unk17[0x29];          // 17
    RegionObjList257d50* childrenList; // 40
    RegionObj257d50* parent;           // 48
};
