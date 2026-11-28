// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// RegionObjNode257ca0, RegionObjList257ca0, RegionObj257ca0, UpdateChildren, ClampToParent, SetMinimumSlope, item, next, head, minSlope, maxSlope, childrenList, parent: GUESS(low)
#pragma once

#include <cstdint>

class RegionObj257ca0;

struct RegionObjNode257ca0
{
    RegionObj257ca0* item;      // 00
    RegionObjNode257ca0* next;  // 08
};

struct RegionObjList257ca0
{
    std::uint64_t unk00;       // 00
    RegionObjNode257ca0 head;  // 08
};

class RegionObj257ca0
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

    bool SetMinimumSlope(std::uint8_t value);

    std::uint8_t unk00[0x15];          // 00
    std::uint8_t minSlope;             // 15
    std::uint8_t maxSlope;             // 16
    std::uint8_t unk17[0x29];          // 17
    RegionObjList257ca0* childrenList; // 40
    RegionObj257ca0* parent;           // 48
};
