// Source exposure: binary-analysis (pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422 (TestBit, CC0-1.0)
// Sky, SkyOwner, SkyData, SkyInner, g_skyOwner, unk48, unk8D0, unk20, unk30: GUESS(low)
// TestBit: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct SkyInner
{
    std::uint8_t pad00[0x20];
    void* unk20;  // 0x20
    std::uint8_t pad28[0x8];
    std::uint32_t unk30;  // 0x30
};

struct SkyData
{
    std::uint8_t pad00[0x8D0];
    SkyInner* unk8D0;  // 0x8D0
};

struct SkyOwner
{
    std::uint8_t pad00[0x48];
    SkyData* unk48;  // 0x48
};

extern SkyOwner* g_skyOwner;

// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value.
inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

class Sky
{
public:
    static bool Function418540();  // compared: 0x418540
};
