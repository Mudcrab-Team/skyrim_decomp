// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: NiTArray220f10::RemoveEnd, treated as adapted: shaped like NiTArray::RemoveEnd in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/niparticle/nimeshpsysdata.cpp:1292
// SPDX-License-Identifier: CC0-1.0
// NiFree220f10, ArrayItem220f10, NiTArray220f10, ArrayOwnerBase220f10, ArrayOwner220f10, RemoveEnd, data, maxSize, firstFreeIdx, size, growBy, items: GUESS(low)
#pragma once

#include <cstdint>

void NiFree220f10(void* ptr);

struct ArrayItem220f10
{
    std::uint64_t unk00;  // 00
    std::uint64_t unk08;  // 08
};

static_assert(sizeof(ArrayItem220f10) == 0x10, "ArrayItem220f10 size");

class NiTArray220f10
{
public:
    virtual ~NiTArray220f10()
    {
        NiFree220f10(data);
    }

    ArrayItem220f10* RemoveEnd()
    {
        if (firstFreeIdx == 0)
        {
            return nullptr;
        }
        --firstFreeIdx;
        ArrayItem220f10* item = data[firstFreeIdx];
        data[firstFreeIdx] = nullptr;
        if (item)
        {
            --size;
        }
        return item;
    }

    ArrayItem220f10** data;      // 08
    std::uint16_t maxSize;       // 10
    std::uint16_t firstFreeIdx;  // 12
    std::uint16_t size;          // 14
    std::uint16_t growBy;        // 16
};

class ArrayOwnerBase220f10
{
public:
    virtual ~ArrayOwnerBase220f10()
    {
    }

    std::uint64_t unk08;  // 08
};

class ArrayOwner220f10 : public ArrayOwnerBase220f10
{
public:
    ~ArrayOwner220f10() override;

    NiTArray220f10 items;  // 10
};
