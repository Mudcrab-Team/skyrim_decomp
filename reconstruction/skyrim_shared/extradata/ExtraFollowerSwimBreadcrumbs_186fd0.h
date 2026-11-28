// Source exposure: mixed (pinned image listing and CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// ExtraFollowerSwimBreadcrumbs, BSExtraData, NiPoint3, leaderState, leaderLocation, leaderNavMeshID, crumbs: CRASHLOGGER_PDB(59818@2026.10.24)
// CrumbList, gZeroPoint, next, item, nextNode: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct NiPoint3
{
    NiPoint3(const NiPoint3& a_rhs) : x(a_rhs.x), y(a_rhs.y), z(a_rhs.z) {}

    float x;
    float y;
    float z;
};

extern const NiPoint3 gZeroPoint;

struct CrumbList
{
    std::uint64_t item;
    CrumbList* nextNode;
};

class BSExtraData
{
public:
    BSExtraData() : next(nullptr) {}
    virtual ~BSExtraData();

    BSExtraData* next;  // 08
};

class ExtraFollowerSwimBreadcrumbs : public BSExtraData
{
public:
    ExtraFollowerSwimBreadcrumbs();  // compared: 0x186fd0

    std::uint32_t leaderState;      // 10
    NiPoint3 leaderLocation;        // 14
    std::uint32_t leaderNavMeshID;  // 20
    std::uint32_t reserved24;       // 24
    CrumbList crumbs;               // 28
};
static_assert(sizeof(ExtraFollowerSwimBreadcrumbs) == 0x38, "size");
