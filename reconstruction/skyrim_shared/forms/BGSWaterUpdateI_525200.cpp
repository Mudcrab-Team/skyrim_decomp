// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x525200 BGSWaterCollisionManager::BGSWaterUpdateI::UpdateCameraInWater
#include "BGSWaterUpdateI_525200.h"

// Notify all active water-update listeners when the camera is in water.
void BGSWaterCollisionManager::BGSWaterUpdateI::UpdateCameraInWater()
{
    for (BGSWaterCollisionManager::BGSWaterUpdateI* node = gWaterUpdateList; node; node = node->next) {
        if (node->ShouldUpdate()) {
            node->OnUpdateCamera();
        }
    }
}
