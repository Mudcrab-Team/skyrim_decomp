// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// BGSWaterCollisionManager, BGSWaterUpdateI, BGSWaterCollisionManager::BGSWaterUpdateI::Link: CRASHLOGGER_PDB(59818@2026.10.24)
// gWaterUpdateList, next: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BGSWaterCollisionManager
{
public:
    class BGSWaterUpdateI
    {
    public:
        void Link();  // compared: 0x525240

        std::uint8_t     unk00[0x28];  // 00
        BGSWaterUpdateI* next;         // 28
    };
};
static_assert(offsetof(BGSWaterCollisionManager::BGSWaterUpdateI, next) == 0x28, "next offset");

extern BGSWaterCollisionManager::BGSWaterUpdateI* gWaterUpdateList;
