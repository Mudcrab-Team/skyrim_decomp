// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// NiPSysData, NiPSysData::sub_140C886C0: CRASHLOGGER_PDB(59818@2026.10.24)
// NiFree, SetSubtextureOffsets, subtextureOffsets, subtextureOffsetCount: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

void NiFree(void* a_ptr);

class NiPSysData
{
public:
    void SetSubtextureOffsets(void* a_offsets, std::uint32_t a_count);  // compared: 0xf14df0

    std::uint8_t unk00[0x60];  // 00
    void* subtextureOffsets;  // 60
    std::uint32_t subtextureOffsetCount;  // 68
};
static_assert(offsetof(NiPSysData, subtextureOffsets) == 0x60, "subtextureOffsets offset");
static_assert(offsetof(NiPSysData, subtextureOffsetCount) == 0x68, "subtextureOffsetCount offset");
