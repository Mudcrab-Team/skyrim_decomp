// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: NiTMap217020::GetFirstPos and GetNext, treated as adapted: shaped like NiTMapBase::GetFirstPos and NiTMapBase::GetNext in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nimain/nitmapbase.inl:130
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nimain/nipersistentsrctexturerendererdata.cpp:745
// SPDX-License-Identifier: CC0-1.0
// NiTMapEntry217020, NiTMapItem217020, NiTMap217020, NiTMapOwner217020, SumEntrySizes, HashIndex, GetFirstPos, GetNext, size, next, key, val, hashSize, hashTable, count, map, unk00: GUESS(low)
#pragma once

#include <cstdint>

struct NiTMapEntry217020
{
    std::uint64_t unk00;  // 00
    std::uint32_t size;   // 08
};

struct NiTMapItem217020
{
    NiTMapItem217020* next;  // 00
    void* key;               // 08
    NiTMapEntry217020* val;  // 10
};

class NiTMap217020
{
public:
    virtual ~NiTMap217020();
    virtual std::uint32_t HashIndex(void* key) const;

    NiTMapItem217020* GetFirstPos() const
    {
        for (std::uint32_t i = 0; i < hashSize; ++i)
        {
            if (hashTable[i])
            {
                return hashTable[i];
            }
        }
        return nullptr;
    }

    void GetNext(NiTMapItem217020*& pos, void*& key, NiTMapEntry217020*& val) const
    {
        NiTMapItem217020* item = pos;
        key = item->key;
        val = item->val;
        if (item->next)
        {
            pos = item->next;
            return;
        }
        std::uint32_t idx = HashIndex(item->key) + 1;
        for (; idx < hashSize; ++idx)
        {
            if (hashTable[idx])
            {
                pos = hashTable[idx];
                return;
            }
        }
        pos = nullptr;
    }

    std::uint32_t hashSize;        // 08
    NiTMapItem217020** hashTable;  // 10
    std::uint32_t count;           // 18
};

class NiTMapOwner217020
{
public:
    std::uint32_t SumEntrySizes() const;

    std::uint64_t unk00;  // 00
    NiTMap217020 map;     // 08
};
