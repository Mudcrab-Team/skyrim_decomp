// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x52c670 TESWaterSystem::Function52c670
// Adapted bodies: none
#include "TESWaterSystem_52c670.h"

WaterNode* TESWaterSystem::Function52c670(WaterOwner* a_owner)
{
    if (a_owner) {
        WaterNode* node = a_owner->unk70();
        if (node) {
            ++counter14;
            if (node->unk03()) {
                WaterNode* next = *node->link118;
                if (next && next->unk03()) {
                    return *next->link118;
                }
            }
        }
    }
    return nullptr;
}
