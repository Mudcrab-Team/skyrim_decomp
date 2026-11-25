// Source exposure: mixed (sibling shape and the pinned image listing).
// Code origin: adapted from the cited sibling body; layout checked against the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Shared/Havok/BGSZoneTargetListener.cpp:151
// BGSZoneTargetListener, BGSZoneTargetListener::~BGSZoneTargetListener, EmptyList, ZoneEntry: SIBLING(fo4-private@1b765c70, author-permission)
// pZones, pNext: GUESS(medium); the names the sibling body uses for these members
// unk08: GUESS(low)
#pragma once

#include <cstdint>

class ZoneEntry
{
public:
    virtual ~ZoneEntry();  // 00

    std::uint64_t unk08;  // 08
    ZoneEntry* pNext;  // 10
};

class BGSZoneTargetListener
{
public:
    virtual ~BGSZoneTargetListener();  // 00
    void EmptyList()
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

    ZoneEntry* pZones;  // 08
};
static_assert(sizeof(BGSZoneTargetListener) == 0x10, "BGSZoneTargetListener size");
