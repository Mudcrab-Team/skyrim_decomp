// Source exposure: mixed (the pinned image listing; sibling shape).
// Code origin: adapted from the cited sibling body; checked against the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Sibling source: fo4-private@1b765c70 src/Shared/Havok/BGSZoneTargetListener.cpp:173
// 0x3f71f0 BGSZoneTargetListener::EmptyList
// CI hash: 0x3f71f0 ?EmptyList@BGSZoneTargetListener@@QEAAXXZ
#include "BGSZoneTargetListener_3f71f0.h"

void BGSZoneTargetListener::EmptyList()
{
    ZoneEntry* pZone = pZones;
    if (pZone) {
        do {
            ZoneEntry* pNext = pZone->pNext;
            delete pZone;
            pZone = pNext;
        } while (pZone);
    }
    pZones = nullptr;
}
