// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled in the header
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x14edb20 ImageSpaceManager::SetupEffects
#include "ImageSpaceManager.h"

void ImageSpaceManager::SetupEffects()
{
    for (std::int32_t i = 0; i < 34; ++i) {
        if (effects.data[i]) {
            effects.data[i]->Setup(this, nullptr);
        }
    }
}
