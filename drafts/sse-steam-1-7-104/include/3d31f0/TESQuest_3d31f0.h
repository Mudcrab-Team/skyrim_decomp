// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial layouts follow the pinned field accesses and cited declarations.
// TESQuest, TESQuest::aliases, BGSBaseAlias, BGSBaseAlias::aliasID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSTArray, BSTArray::_size, ::size: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSTArrayHeapAllocator::_data, ::_capacity: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); allocator members flattened into the stand-in
// TESQuest::GetAlias: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include <cstddef>
#include <cstdint>

template <class T>
class BSTArray
{
public:
    std::uint32_t size() const
    {
        return _size;
    }

    T& operator[](std::uint32_t a_pos)
    {
        return _data[a_pos];
    }

    T*            _data;      // 00
    std::uint32_t _capacity;  // 08
    std::uint32_t unk0C;      // 0C
    std::uint32_t _size;      // 10
    std::uint32_t unk14;      // 14
};
static_assert(sizeof(BSTArray<void*>) == 0x18, "layout differs from CommonLibSSE-NG");

class BGSBaseAlias
{
public:
    std::uint8_t  unk00[0x18];  // 00 - vtable, aliasName, owningQuest
    std::uint32_t aliasID;      // 18 - ALST/ALLS
};

class TESQuest
{
public:
    BGSBaseAlias* GetAlias(std::uint32_t a_aliasID);

    std::uint8_t            unk00[0x58];  // 00 - BGSStoryManagerTreeForm, TESFullName, instance data
    BSTArray<BGSBaseAlias*> aliases;      // 58
};
static_assert(offsetof(TESQuest, aliases) == 0x58, "layout differs from CommonLibSSE-NG");
static_assert(offsetof(BGSBaseAlias, aliasID) == 0x18, "layout differs from CommonLibSSE-NG");
