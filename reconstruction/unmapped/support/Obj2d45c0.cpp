// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2d45c0::GetFirstPos, treated as adapted: shaped like NiTMapBase::GetFirstPos in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nimain/nitmapbase.inl:130
// SPDX-License-Identifier: CC0-1.0
// 0x2d45c0 Obj2d45c0::GetFirstPos
#include "Obj2d45c0.h"

// Guess: return the first non-null bucket head in the hash table.
void* Obj2d45c0::GetFirstPos() const
{
    for (std::uint32_t i = 0; i < m_hashSize; ++i)
    {
        if (m_hashTable[i])
        {
            return m_hashTable[i];
        }
    }
    return nullptr;
}
