// Build id: sse-steam-1-7-104. Source exposure: mixed (community headers; FNV sibling shapes; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Labels: v2
// GetParentWorld, GetParentUseFlag: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// 0x30e140 TESWorldSpace::GetMapModel
// RVA 0x30e140, 101 bytes (compared)
// Adapted bodies: GetParentWorld and GetParentUseFlag follow momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesworldspace.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesworldspace.cpp:75
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/fallout_shared/tesworldspace.cpp:28
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesworldspace.cpp:880
#include "TESWorldSpace_30e140.h"

bool TESWorldSpace::GetParentUseFlag(std::uint32_t a_flag) const
{
    std::uint16_t mask = static_cast<std::uint16_t>(1u << a_flag);
    return (parentUseFlags & mask) != 0;
}

TESWorldSpace* TESWorldSpace::GetParentWorld(std::uint32_t a_flag)
{
    if (parentWorld && !GetParentUseFlag(a_flag)) {
        return nullptr;
    }
    return parentWorld;
}

const char* TESWorldSpace::GetMapModel()
{
    const char* path = nullptr;
    if (GetParentWorld(2)) {
        path = GetParentWorld(2)->model.GetModel();
    }
    if (!path || !*path) {
        path = model.GetModel();
    }
    if (!path || !*path) {
        return kDefaultMapModel;
    }
    return path;
}
