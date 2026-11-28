// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj1c9750::SetSize, treated as adapted: shaped like NiTArray::SetSize in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00c60000_od_ob1_variant.cpp:2566
// SPDX-License-Identifier: CC0-1.0
// Obj1c9750, SetSize, NiMalloc1c9750, NiFree1c9750: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

void* NiMalloc1c9750(std::size_t a_bytes);
void NiFree1c9750(void* a_ptr);

struct Obj1c9750
{
    void SetSize(std::uint32_t a_newSize);  // compared: 0x1c9750

    void* vtable00;         // 00
    void** data08;          // 08
    std::uint16_t cap10;    // 10
    std::uint16_t size12;   // 12
    std::uint16_t count14;  // 14
};
