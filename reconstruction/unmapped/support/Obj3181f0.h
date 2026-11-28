// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// Base3181f0, Derived3181f0, SubObj3181f0, Obj3181f0, Obj3181f0::ClearAll, gActive3181f0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class Base3181f0
{
public:
    virtual ~Base3181f0();
};

class Derived3181f0 : public Base3181f0
{
public:
    virtual ~Derived3181f0();
};

class SubObj3181f0
{
public:
    virtual ~SubObj3181f0();
};

extern void* gActive3181f0;

class Obj3181f0
{
public:
    Base3181f0* GetAt(std::uint32_t a_index);
    void ClearAll();

    std::uint64_t unk00;          // 0x00
    Base3181f0** m_items;         // 0x08
    std::uint32_t m_capacity;     // 0x10
    std::uint32_t m_count;        // 0x14
    std::uint32_t m_usedCount;    // 0x18
    std::uint32_t unk1C;          // 0x1C
    std::uint64_t unk20;          // 0x20
    SubObj3181f0** m_subItems;    // 0x28
    std::uint16_t m_subCapacity;  // 0x30
    std::uint16_t m_subCount;     // 0x32
    std::uint16_t m_subUsed;      // 0x34
};
static_assert(offsetof(Obj3181f0, m_items) == 0x08, "m_items offset");
static_assert(offsetof(Obj3181f0, m_count) == 0x14, "m_count offset");
static_assert(offsetof(Obj3181f0, m_subItems) == 0x28, "m_subItems offset");
static_assert(offsetof(Obj3181f0, m_subCount) == 0x32, "m_subCount offset");
