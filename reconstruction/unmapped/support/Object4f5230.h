// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// Base4f5230, SubData4f5230, Object4f5230, unk08, flagsBA, unkBC, unk00, unk04, unk10, unk14, unk18, unk20, subData: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class Base4f5230
{
public:
    Base4f5230();
    virtual ~Base4f5230();

    std::uint8_t unk08[0xB2];   // 0x008
    std::uint16_t flagsBA;      // 0x0BA
    std::uint8_t unkBC[0x44];   // 0x0BC
};
static_assert(offsetof(Base4f5230, flagsBA) == 0xBA, "Base4f5230 flagsBA offset");
static_assert(sizeof(Base4f5230) == 0x100, "Base4f5230 size");

struct SubData4f5230
{
    SubData4f5230()
        : unk00(0)
        , unk08(nullptr)
        , unk10(0)
        , unk14(0)
        , unk18(nullptr)
        , unk20(0)
    {
    }

    std::uint32_t unk00;  // 0x00
    std::uint32_t unk04;  // 0x04
    void* unk08;          // 0x08
    std::uint32_t unk10;  // 0x10
    std::uint8_t unk14;   // 0x14
    void* unk18;          // 0x18
    std::uint8_t unk20;   // 0x20
};
static_assert(offsetof(SubData4f5230, unk20) == 0x20, "SubData4f5230 unk20 offset");

class Object4f5230 : public Base4f5230
{
public:
    Object4f5230();

    SubData4f5230 subData;  // 0x100
};
static_assert(offsetof(Object4f5230, subData) == 0x100, "subData offset");
