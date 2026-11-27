// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x738e80 BGSLoadGameBuffer::sub_140692600
// Adapted bodies: none
#include "BGSLoadGameBuffer_738e80.h"

// Reads a counted list of keyed float-and-flag entries from the save buffer into a_table.
void BGSLoadGameBuffer::sub_140692600(LoadedValueTable* a_table, KeyIndexFn a_keyToIndex)
{
    std::uint32_t count = 0;
    LoadDataEndian(&count, 4, 4);
    for (std::uint32_t i = 0; i < count; ++i) {
        std::uint32_t key = 0xFFFFFFFFu;
        LoadDataEndian(&key, 4, 4);

        LoadedValueEntry loaded{ 0.0f, true };
        LoadDataEndian(&loaded.value, 4, 4);
        LoadDataEndian(&loaded.flag, 1, 1);

        std::int32_t index = a_keyToIndex(key);
        if (index >= 0) {
            LoadedValueEntry& entry = (*a_table)[index];
            entry.flag = loaded.flag;
            entry.value = loaded.value;
        }
    }
}
