// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESWorldSpace, parentUseFlags, parentWorld, defaultWaterHeight: CRASHLOGGER_PDB(59818@2026.10.24)
// GetDefaultWaterHeight: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// HasParentUseFlag, ResolveParentWorld, unknown000, unknown0A4, unknown160: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

class TESWorldSpace
{
public:
    float GetDefaultWaterHeight() const;

    std::uint8_t   unknown000[0xA2];   // 000
    std::uint16_t  parentUseFlags;     // 0A2
    std::uint8_t   unknown0A4[0xB4];   // 0A4
    TESWorldSpace* parentWorld;        // 158
    std::uint8_t   unknown160[0xB4];   // 160
    float          defaultWaterHeight; // 214
};
static_assert(offsetof(TESWorldSpace, parentUseFlags) == 0xA2, "parentUseFlags offset");
static_assert(offsetof(TESWorldSpace, parentWorld) == 0x158, "parentWorld offset");
static_assert(offsetof(TESWorldSpace, defaultWaterHeight) == 0x214, "defaultWaterHeight offset");
