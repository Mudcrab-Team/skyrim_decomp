// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: MapBase1d70d0::SetAt, treated as adapted: shaped like NiTMapBase::SetAt in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nimain/nitmapbase.inl:44
// SPDX-License-Identifier: CC0-1.0
// 0x1d70d0 MapBase1d70d0::SetAt
#include "MapBase1d70d0.h"

// Inserts or updates the mapped value for the given key in the hash bucket chain.
void MapBase1d70d0::SetAt(MapKey1d70d0 a_key, std::uint32_t a_value)
{
    std::uint32_t index = KeyToHashIndex(a_key);
    MapItem1d70d0* item = hashTable[index];
    while (item) {
        if (IsKeysEqual(a_key, item->key)) {
            item->value = a_value;
            return;
        }
        item = item->next;
    }

    MapItem1d70d0* newItem = NewItem();
    SetValue(newItem, a_key, a_value);
    newItem->next = hashTable[index];
    hashTable[index] = newItem;
    ++count;
}
