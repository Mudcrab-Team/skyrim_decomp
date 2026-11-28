// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: NiTArray221230::RemoveEnd, treated as adapted: shaped like NiTArray::RemoveEnd in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/niparticle/nimeshpsysdata.cpp:1292
// SPDX-License-Identifier: CC0-1.0
// ArrayItem221230, NiTArray221230, ArrayOwner221230, RemoveEnd, ClearItems, data, maxSize, firstFreeIdx, size, growBy, items: GUESS(low)
#pragma once

#include <cstdint>

struct ArrayItem221230
{
    std::uint64_t unk00;  // 00
    std::uint64_t unk08;  // 08
};

static_assert(sizeof(ArrayItem221230) == 0x10, "ArrayItem221230 size");

class NiTArray221230
{
public:
    virtual ~NiTArray221230();

    ArrayItem221230* RemoveEnd()
    {
        if (firstFreeIdx == 0)
        {
            return nullptr;
        }
        --firstFreeIdx;
        ArrayItem221230* item = data[firstFreeIdx];
        data[firstFreeIdx] = nullptr;
        if (item)
        {
            --size;
        }
        return item;
    }

    ArrayItem221230** data;      // 08
    std::uint16_t maxSize;       // 10
    std::uint16_t firstFreeIdx;  // 12
    std::uint16_t size;          // 14
    std::uint16_t growBy;        // 16
};

class ArrayOwner221230
{
public:
    bool ClearItems();

    std::uint8_t unk00[0x10];  // 00
    NiTArray221230 items;      // 10
};
