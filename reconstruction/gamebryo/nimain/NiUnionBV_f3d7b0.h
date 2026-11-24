// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// NiUnionBV: GUESS(low); the class is the placeholder owner
// RemoveAllChildren: GUESS(low); the name is made up
// NiBoundingVolume: STANDIN GUESS(low); only the destructor slot is declared
// children, capacity, count, elementCount, pad00, unk00, unk01: GUESS(low); members at 0x10, 0x18, 0x1A, 0x1C and slot placeholders
#pragma once

#include <cstdint>

class NiBoundingVolume
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual ~NiBoundingVolume();

    std::uint8_t pad00[0x8];
};

class NiUnionBV : public NiBoundingVolume
{
public:
    void RemoveAllChildren();  // compared: 0xf3d7b0

    NiBoundingVolume** children;
    std::uint16_t capacity;
    std::uint16_t count;
    std::uint16_t elementCount;
};
