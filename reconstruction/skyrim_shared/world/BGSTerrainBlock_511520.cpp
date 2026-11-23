// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x511520 BGSTerrainBlock::GetBlockData
// Adapted bodies: none
#include "BGSTerrainBlock_511520.h"

void* BGSTerrainBlock::GetBlockData(std::uint32_t a_which)
{
    if (node) {
        BlockObject* obj = node->object;
        if (obj && obj->GetRTTI() == &rttiTarget) {
            BlockData* d = obj->data;
            return a_which == 0 ? d->first : d->second;
        }
    }
    return nullptr;
}
