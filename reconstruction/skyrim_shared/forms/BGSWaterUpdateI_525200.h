// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// BGSWaterCollisionManager, BGSWaterUpdateI, BGSWaterCollisionManager::BGSWaterUpdateI::UpdateCameraInWater: CRASHLOGGER_PDB(59818@2026.10.24)
// gWaterUpdateList, ShouldUpdate, OnUpdateCamera, next: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BGSWaterCollisionManager
{
public:
    class BGSWaterUpdateI
    {
    public:
        virtual ~BGSWaterUpdateI();          // 00
        virtual void Unk01();                // 08
        virtual bool ShouldUpdate();         // 10
        virtual void OnUpdateCamera();       // 18

        static void UpdateCameraInWater();   // compared: 0x525200

        std::uint8_t     unk08[0x20];  // 08
        BGSWaterUpdateI* next;         // 28
    };
};
static_assert(offsetof(BGSWaterCollisionManager::BGSWaterUpdateI, next) == 0x28, "next offset");

extern BGSWaterCollisionManager::BGSWaterUpdateI* gWaterUpdateList;
