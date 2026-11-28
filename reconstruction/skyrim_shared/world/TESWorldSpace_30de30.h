// Source exposure: mixed (pinned image, cited public declarations and the FNV sibling).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial layout follows the pinned field accesses and cited declarations.
// Adapted bodies: GetParentWorld and GetParentUseFlag follow momusdigital/fnv_decomp@2b07cb3e and momusdigital/f3_decomp@f5bac1b5 src/fallout_shared/tesworldspace.cpp (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesworldspace.cpp:80
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/fallout_shared/tesworldspace.cpp:28
// TESWorldSpace, ::terrainManager, ::parentUseFlags, ::parentWorld, ::defaultLandHeight: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSTerrainManager: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetWorldTerrainManager, GetParentWorld, GetParentUseFlag, PARENT_USE_FLAG, PU_LAND, PU_LOD: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0)
// GetDefaultLandHeight: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include <cstddef>
#include <cstdint>

class BGSTerrainManager;

class TESWorldSpace
{
public:
    // Bit indices into parentUseFlags.
    enum PARENT_USE_FLAG
    {
        PU_LAND = 0,
        PU_LOD = 1
    };

    BGSTerrainManager* GetWorldTerrainManager();
    float GetDefaultLandHeight();

    // True when this world takes the given data from its parent.
    bool GetParentUseFlag(PARENT_USE_FLAG a_index) const
    {
        std::uint16_t mask = static_cast<std::uint16_t>(1u << a_index);
        return (parentUseFlags & mask) != 0;
    }

    // The parent world, or null when the parent is not used for the given data.
    TESWorldSpace* GetParentWorld(PARENT_USE_FLAG a_flag)
    {
        if (parentWorld && !GetParentUseFlag(a_flag)) {
            return nullptr;
        }
        return parentWorld;
    }

    std::uint8_t       unknown000[0x90];  // 000 - TESForm, TESFullName, cell map, persistent cell
    BGSTerrainManager* terrainManager;    // 090
    std::uint8_t       unknown098[0xA];   // 098
    std::uint16_t      parentUseFlags;    // 0A2 - PNAM
    std::uint8_t       unknown0A4[0xB4];  // 0A4
    TESWorldSpace*     parentWorld;       // 158 - WNAM
    std::uint8_t       unknown160[0xB0];  // 160
    float              defaultLandHeight; // 210 - DNAM
};
static_assert(offsetof(TESWorldSpace, parentWorld) == 0x158, "layout differs from CommonLibSSE-NG");
static_assert(offsetof(TESWorldSpace, defaultLandHeight) == 0x210, "layout differs from CommonLibSSE-NG");
