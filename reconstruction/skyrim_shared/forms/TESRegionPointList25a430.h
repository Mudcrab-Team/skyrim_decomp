// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// TESRegionPointList25a430, TESRegionPointList25a430::Find: CRASHLOGGER_PDB(59818@2026.10.24)
// RegionPoint25a430, RegionPointNode25a430, x, y, item, next, head, count: GUESS(low)
#pragma once

#include <cstdint>

struct RegionPoint25a430
{
    float x;  // 00
    float y;  // 04
};

struct RegionPointNode25a430
{
    RegionPoint25a430* item;      // 00
    RegionPointNode25a430* next;  // 08
};

class TESRegionPointList25a430
{
public:
    RegionPoint25a430* Find(RegionPoint25a430* point, float tolerance);

    RegionPointNode25a430 head;  // 00
    std::uint8_t unk10[0x20];    // 10
    std::uint32_t count;         // 30
};
