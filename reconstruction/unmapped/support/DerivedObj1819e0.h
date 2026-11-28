// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// BaseObj1819e0, Handle1819e0, DerivedObj1819e0, gInvalidHandle1819e0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

extern std::uint32_t gInvalidHandle1819e0;

struct Handle1819e0
{
    Handle1819e0() : value(gInvalidHandle1819e0) {}
    std::uint32_t value;  // 00
};

class BaseObj1819e0
{
public:
    BaseObj1819e0() : next(0) {}
    virtual ~BaseObj1819e0() {}

    void* next;  // 08
};

class DerivedObj1819e0 : public BaseObj1819e0
{
public:
    DerivedObj1819e0();  // compared: 0x1819e0

    void* unk10;               // 10
    Handle1819e0 handle;       // 18
    std::uint32_t unk1C : 16;  // 1C
    std::uint8_t flag0 : 1;    // 20
    std::uint8_t flag1 : 1;    // 20
    std::uint8_t flag2 : 1;    // 20
};
