// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2d45c0::GetFirstPos, treated as adapted: shaped like NiTMapBase::GetFirstPos in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nimain/nitmapbase.inl:130
// SPDX-License-Identifier: CC0-1.0
// Obj2d45c0, Obj2d45c0::GetFirstPos: GUESS(low)
#pragma once

#include <cstdint>

class Obj2d45c0
{
public:
    void* GetFirstPos() const;

    std::uint64_t unk00;       // 0x00
    std::uint32_t m_hashSize;  // 0x08
    void** m_hashTable;        // 0x10
};
