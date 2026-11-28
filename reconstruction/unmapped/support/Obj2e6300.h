// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: IsKindOf, treated as adapted: shaped like NiRTTI::IsKindOf in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00560000_o2.cpp:19104
// SPDX-License-Identifier: CC0-1.0
// RTTI2e6300, gRTTI2e6300, Obj2e6300, Obj2e6300::HasNonEmptyTarget: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct RTTI2e6300
{
    const char* m_name;    // 0x00
    RTTI2e6300* m_parent;  // 0x08
};

extern RTTI2e6300 gRTTI2e6300;

class Obj2e6300
{
public:
    virtual ~Obj2e6300();
    virtual void Slot01();
    virtual const RTTI2e6300* GetRTTI() const;
    virtual Obj2e6300* AsNode();

    static bool HasNonEmptyTarget(Obj2e6300* a_node);

    std::uint64_t unk08[34];      // 0x08
    Obj2e6300** m_children;       // 0x118
    std::uint16_t unk120;         // 0x120
    std::uint16_t m_capacity;     // 0x122
    std::uint16_t m_count;        // 0x124
};
static_assert(offsetof(Obj2e6300, m_children) == 0x118, "m_children offset");
static_assert(offsetof(Obj2e6300, m_capacity) == 0x122, "m_capacity offset");
static_assert(offsetof(Obj2e6300, m_count) == 0x124, "m_count offset");
