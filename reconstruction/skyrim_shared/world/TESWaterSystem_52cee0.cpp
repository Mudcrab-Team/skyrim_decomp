// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x52cee0 TESWaterSystem::Function52cee0
// Adapted bodies: none
#include "TESWaterSystem_52cee0.h"

WaterItem* TESWaterSystem::Function52cee0()
{
    for (std::uint32_t i = 0; i < count; ++i) {
        WaterItem* item = items[i];
        if ((item->flags & 0x1E0) == 0x100 && !(item->flags & 0x600)) {
            return item;
        }
    }
    return nullptr;
}
