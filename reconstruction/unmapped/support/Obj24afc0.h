// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj24afc0::SetSize, treated as adapted: shaped like NiTArray::SetSize in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nimain/nitarray.inl:97
// SPDX-License-Identifier: CC0-1.0
// Obj24afc0, SetSize, AllocBuffer24afc0, FreeBuffer24afc0, data, maxSize, firstFree, effectiveSize: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

void** AllocBuffer24afc0(std::size_t bytes);
void FreeBuffer24afc0(void* ptr);

class Obj24afc0
{
public:
    virtual ~Obj24afc0();

    void SetSize(std::uint32_t newSize);

    void** data;                  // 08
    std::uint32_t maxSize;        // 10
    std::uint32_t firstFree;      // 14
    std::uint32_t effectiveSize;  // 18
};
