// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: TestBit from momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422 (CC0-1.0)
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
// GrenadeProjectile, GrenadeProjectile::IsLive, ProjectileBaseStandIn, baseFlags, baseDuration, TestBit: GUESS(low); TestBit takes the flag word by value
#pragma once

#include <cstdint>
#include <cstddef>

inline bool TestBit(uint32_t a_flags, uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

class ProjectileBaseStandIn
{
public:
    uint8_t unk00[0x80];
    uint32_t baseFlags;
    uint8_t unk84[0x20];
    float baseDuration;
};

class GrenadeProjectile
{
public:
    uint8_t unk00[0x40];
    ProjectileBaseStandIn* baseForm;

    bool IsLive();  // compared: 0x7ec6d0
};
