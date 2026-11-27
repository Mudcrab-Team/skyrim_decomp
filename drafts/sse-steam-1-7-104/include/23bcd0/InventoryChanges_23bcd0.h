// Exposure detail: (community declarations and pinned image analysis).
// Source exposure: mixed
// Code origin: original reconstruction from the pinned image; declarations as labelled.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x23bcd0 InventoryChanges::AddCountToExistingEntry
// InventoryChanges::AddCountToExistingEntry: GUESS(low); adds the supplied count to the first matching entry
// InventoryChanges, InventoryChanges::entryList, InventoryEntryData, InventoryEntryData::object, InventoryEntryData::extraLists, InventoryEntryData::countDelta, BSSimpleList, TESBoundObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSSimpleList::item, BSSimpleList::next: GUESS(low); minimal linked-list node fields

#pragma once
#include <cstdint>

class TESBoundObject;
class InventoryEntryData
{
public:
    TESBoundObject* object;  // 00
    void* extraLists;  // 08
    std::int32_t countDelta;  // 10
};
template <class T>
struct BSSimpleList
{
    T item;  // 00
    BSSimpleList* next;  // 08
};
class InventoryChanges
{
public:
    void AddCountToExistingEntry(TESBoundObject* object, std::int32_t count);
    BSSimpleList<InventoryEntryData*>* entryList;  // 00
};
