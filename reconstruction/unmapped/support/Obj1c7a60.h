// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj1c7a60::Compact, treated as adapted: shaped like NiTArray::Compact in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00c60000_od_ob1_variant.cpp:1415
// SPDX-License-Identifier: CC0-1.0
// Obj1c7a60, Compact, NiMalloc1c7a60, NiFree1c7a60: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

void* NiMalloc1c7a60(std::size_t a_bytes);
void NiFree1c7a60(void* a_ptr);

struct Obj1c7a60
{
    void Compact();  // compared: 0x1c7a60

    void* vtable00;         // 00
    void** data08;          // 08
    std::uint16_t cap10;    // 10
    std::uint16_t size12;   // 12
    std::uint16_t count14;  // 14
};
