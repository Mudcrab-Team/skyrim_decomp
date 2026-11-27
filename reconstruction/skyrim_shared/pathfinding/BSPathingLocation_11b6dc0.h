// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSNavmeshInfo, BSPathingLocation: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSPathingLocation::GetBestNavMeshInfo, BSPathingLocation::navMeshInfo, BSPathingLocation::navMeshInfoArray, BSPathingLocation::flags: CRASHLOGGER_PDB(59818@2026.10.24)
// NavMeshInfoArray, NavMeshInfoArray::data, BSPathingLocation::unk00, BSPathingLocation::unk20, BSPathingLocation::unk2B: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct BSNavmeshInfo;

struct NavMeshInfoArray
{
    BSNavmeshInfo** data;
};

class BSPathingLocation
{
public:
    BSNavmeshInfo* GetBestNavMeshInfo() const;

    std::uint8_t unk00[0x10];
    BSNavmeshInfo* navMeshInfo;
    NavMeshInfoArray* navMeshInfoArray;
    std::uint8_t unk20[0x0A];
    std::uint8_t flags;
    std::uint8_t unk2B[5];
};
static_assert(offsetof(BSPathingLocation, navMeshInfo) == 0x10, "navMeshInfo offset");
static_assert(offsetof(BSPathingLocation, navMeshInfoArray) == 0x18, "navMeshInfoArray offset");
static_assert(offsetof(BSPathingLocation, flags) == 0x2A, "flags offset");
static_assert(sizeof(BSPathingLocation) == 0x30, "BSPathingLocation size");
