// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// BGSLoadGameBuffer: EXE_RTTI
// BGSLoadGameBuffer::sub_140692600: CRASHLOGGER_PDB(59818@2026.10.24)
// BGSLoadGameBuffer::LoadDataEndian: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// LoadedValueEntry, LoadedValueEntry::value, LoadedValueEntry::flag, LoadedValueTable, LoadedValueTable::entries, KeyIndexFn: GUESS(low); entry layout and callback observed in listing
#pragma once

#include <cstdint>

struct LoadedValueEntry
{
    float value;  // 00
    bool  flag;   // 04
};
static_assert(sizeof(LoadedValueEntry) == 0x8, "LoadedValueEntry size");

struct LoadedValueTable
{
    LoadedValueEntry& operator[](std::uint32_t a_index) const { return entries[a_index]; }

    LoadedValueEntry* entries;  // 00
};

using KeyIndexFn = std::int32_t (*)(std::uint32_t);

class BGSLoadGameBuffer
{
public:
    void LoadDataEndian(void* a_data, std::uint32_t a_offset, std::uint32_t a_size);
    void sub_140692600(LoadedValueTable* a_table, KeyIndexFn a_keyToIndex);
};
