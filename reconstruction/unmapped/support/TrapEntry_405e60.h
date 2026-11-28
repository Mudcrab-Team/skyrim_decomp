// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// TrapEntry, TrapEntry::Func2_1403A6560: CRASHLOGGER_PDB(59818@2026.10.24)
// TrapNode405e60, OnNotify, next, head: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class TrapEntry;

class TrapNode405e60
{
public:
    virtual ~TrapNode405e60();                      // 00
    virtual void OnNotify(TrapEntry* a_entry, void* a_arg);  // 08

    std::uint64_t   unk08;  // 08
    TrapNode405e60* next;   // 10
};
static_assert(offsetof(TrapNode405e60, next) == 0x10, "next offset");

class TrapEntry
{
public:
    void Func2_1403A6560(void* a_arg);  // compared: 0x405e60

    std::uint8_t    unk00[0x28];  // 00
    TrapNode405e60* head;         // 28
};
static_assert(offsetof(TrapEntry, head) == 0x28, "head offset");
