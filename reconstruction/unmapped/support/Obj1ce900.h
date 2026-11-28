// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Target1ce900, Obj1ce900, SetTarget: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Target1ce900
{
    virtual ~Target1ce900();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual std::uint32_t GetVal();

    std::uint8_t unk08[0x50];    // 008
    std::int32_t val58;          // 058
    std::uint8_t unk5C[0x114];   // 05C
    std::int32_t val170;         // 170
};

struct Obj1ce900
{
    void SetTarget(Target1ce900* a_target);  // compared: 0x1ce900

    std::uint8_t unk00[0x38];     // 000
    Target1ce900* target38;       // 038
    std::uint8_t unk40[0x264];    // 040
    std::uint32_t field2A4;       // 2A4
    std::int32_t field2A8;        // 2A8
};
