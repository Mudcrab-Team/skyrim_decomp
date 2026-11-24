// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BGSAIWorldLocationPointRadius, BGSAIWorldLocationPointRadius::IsWithinRadius: GUESS(low)
// PositionHolder, x, y, z, pad00, pad54: GUESS(low); minimal stand-in for the argument, position at 0x54
// HasLocation, unk00 to unk02, posX, posY, posZ, radius, pad14, pad2C: GUESS(low); slot 3 is a bool query, members at 0x8, 0xC, 0x10 and 0x28
#pragma once

#include <cstdint>

struct PositionHolder
{
    std::uint8_t pad00[0x54];
    float x;
    float y;
    float z;
};

class BGSAIWorldLocationPointRadius
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual bool HasLocation();

    bool IsWithinRadius(const PositionHolder& a_other);  // compared: 0x448d90

    float posX;
    float posY;
    float posZ;
    std::uint8_t pad14[0x14];
    float radius;
};
