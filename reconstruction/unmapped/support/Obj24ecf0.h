// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Map24ecf0::GetAt, treated as adapted: shaped like NiTMapBase::GetAt in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nimain/nitmapbase.inl:6
// SPDX-License-Identifier: CC0-1.0
// MapEntry24ecf0, Map24ecf0, Obj24ecf0, HashKey, KeysEqual, GetAt, OnFound, OnFinish, Dispatch, next, key, value, hashSize, buckets, flag08, context, map: GUESS(low)
#pragma once

#include <cstdint>

struct MapEntry24ecf0
{
    MapEntry24ecf0* next;  // 00
    const void* key;       // 08
    void* value;           // 10
};

class Map24ecf0
{
public:
    virtual ~Map24ecf0();
    virtual std::uint32_t HashKey(const void* key) const;
    virtual bool KeysEqual(const void* a, const void* b) const;

    bool GetAt(const void* key, void*& outValue) const
    {
        std::uint32_t idx = HashKey(key);
        for (MapEntry24ecf0* entry = buckets[idx]; entry != nullptr; entry = entry->next)
        {
            if (KeysEqual(key, entry->key))
            {
                outValue = entry->value;
                return true;
            }
        }
        return false;
    }

    std::uint32_t hashSize;    // 08
    MapEntry24ecf0** buckets;  // 10
};

class Obj24ecf0
{
public:
    virtual ~Obj24ecf0();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual bool OnFound(void* value);  // 20
    virtual void V05();
    virtual void OnFinish();            // 30

    bool Dispatch(void* ctx, const void* key);

    bool flag08;                 // 08
    std::uint8_t unk09[0x107];   // 09
    void* context;               // 110
    Map24ecf0 map;               // 118
};
