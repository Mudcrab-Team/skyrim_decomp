// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BGSStoryEvent: CRASHLOGGER_PDB(59818@2026.10.24)
// unk00, unk08, unk10, unk18, unk20, unk28, unk30: GUESS(low) STANDIN
#pragma once

#include <cstdint>

class BGSStoryEvent
{
public:
    BGSStoryEvent();

    std::uint64_t unk00;
    std::uint64_t unk08;
    std::uint64_t unk10;
    std::uint64_t unk18;
    std::uint64_t unk20;
    std::uint64_t unk28;
    std::uint64_t unk30;
};

static_assert(sizeof(BGSStoryEvent) == 0x38, "BGSStoryEvent size");
