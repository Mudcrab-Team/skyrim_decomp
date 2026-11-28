// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: MapBase1d70d0::SetAt, treated as adapted: shaped like NiTMapBase::SetAt in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nimain/nitmapbase.inl:44
// SPDX-License-Identifier: CC0-1.0
// MapKey1d70d0, MapItem1d70d0, MapBase1d70d0, SetAt, KeyToHashIndex, IsKeysEqual, SetValue, ClearValue, NewItem, hashSize, hashTable, count, next, key, value, bits: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

// guess: the key is a handle-like class that declares its own copy constructor.
struct MapKey1d70d0
{
    MapKey1d70d0() = default;
    MapKey1d70d0(const MapKey1d70d0& a_other) : bits(a_other.bits) {}

    std::uint32_t bits;  // 00
};
static_assert(sizeof(MapKey1d70d0) == 0x04, "MapKey1d70d0 size");

struct MapItem1d70d0
{
    MapItem1d70d0* next;  // 00
    MapKey1d70d0 key;     // 08
    std::uint32_t value;  // 0C
};
static_assert(offsetof(MapItem1d70d0, key) == 0x08, "MapItem1d70d0::key offset");
static_assert(offsetof(MapItem1d70d0, value) == 0x0C, "MapItem1d70d0::value offset");

class MapBase1d70d0
{
public:
    virtual ~MapBase1d70d0();
    virtual std::uint32_t KeyToHashIndex(MapKey1d70d0 a_key) const;
    virtual bool IsKeysEqual(MapKey1d70d0 a_key1, MapKey1d70d0 a_key2) const;
    virtual void SetValue(MapItem1d70d0* a_item, MapKey1d70d0 a_key, std::uint32_t a_value);
    virtual void ClearValue(MapItem1d70d0* a_item);
    virtual MapItem1d70d0* NewItem();

    void SetAt(MapKey1d70d0 a_key, std::uint32_t a_value);  // compared: 0x1d70d0

    std::uint32_t hashSize;      // 08
    MapItem1d70d0** hashTable;   // 10
    std::uint32_t count;         // 18
};
static_assert(offsetof(MapBase1d70d0, hashTable) == 0x10, "MapBase1d70d0::hashTable offset");
static_assert(offsetof(MapBase1d70d0, count) == 0x18, "MapBase1d70d0::count offset");
