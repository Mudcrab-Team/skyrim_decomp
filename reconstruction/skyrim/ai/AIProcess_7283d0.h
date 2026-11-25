// Source exposure: mixed (community declarations, community PDB names, and local binary analysis).
// Code origin: original handwritten reconstruction from the assigned local listing; minimal declarations use cited name and layout sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// AIProcess, AIProcess::HasPerkEntries: CRASHLOGGER_PDB(59818@2026.10.24)
// AIProcess::middleHigh, MiddleHighProcessData, MiddleHighProcessData::perkData, AIPerkData, AIPerkData::perkEntryArrays: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// PerkEntryArray, PerkEntryArray::entries, PerkEntryArray::capacity, PerkEntryArray::size, PerkEntryArray::reserved, MiddleHighProcessData::unknown00, AIProcess::unknown00: GUESS(low); minimal accessed container and process fields
#pragma once

#include <cstddef>
#include <cstdint>

struct PerkEntryArray
{
    void** entries;
    std::uint32_t capacity;
    std::uint32_t reserved;
    std::uint32_t size;
    std::uint32_t reserved14;
};
static_assert(sizeof(PerkEntryArray) == 0x18, "perk array stride");

struct AIPerkData
{
    PerkEntryArray perkEntryArrays[92];
};

struct MiddleHighProcessData
{
    std::uint8_t unknown00[0x288];
    AIPerkData* perkData;
};
static_assert(offsetof(MiddleHighProcessData, perkData) == 0x288, "perk data offset");

class AIProcess
{
public:
    bool HasPerkEntries(std::uint8_t entryPoint) const;

    void* unknown00;
    MiddleHighProcessData* middleHigh;
};
static_assert(offsetof(AIProcess, middleHigh) == 0x8, "middle-high process offset");
