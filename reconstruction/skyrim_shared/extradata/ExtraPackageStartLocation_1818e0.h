// Source exposure: mixed (pinned image listing and CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// ExtraPackageStartLocation, BSExtraData, WORLD_LOCATION, NiPoint3, worldLoc: CRASHLOGGER_PDB(59818@2026.10.24)
// location, pos, rot, next: GUESS(low)
#pragma once

#include <cstddef>

struct NiPoint3
{
    NiPoint3() : x(0.0f), y(0.0f), z(0.0f) {}

    float x;
    float y;
    float z;
};

struct WORLD_LOCATION
{
    void* location;  // 00
    NiPoint3 pos;    // 08
    float rot;       // 14
};
static_assert(sizeof(WORLD_LOCATION) == 0x18, "WORLD_LOCATION size");

class BSExtraData
{
public:
    BSExtraData() : next(nullptr) {}
    virtual ~BSExtraData();

    BSExtraData* next;  // 08
};

class ExtraPackageStartLocation : public BSExtraData
{
public:
    ExtraPackageStartLocation(void* a_loc1, void* a_loc2, const NiPoint3& a_pos, float a_rot);  // compared: 0x1818e0

    WORLD_LOCATION worldLoc;  // 10
};
static_assert(sizeof(ExtraPackageStartLocation) == 0x28, "size");
