// Build id: sse-steam-1-7-104. Source exposure: mixed (community declarations; FNV sibling shapes; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Labels: v2
// TESWorldSpace, climate, parentUseFlags, parentWorld: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); file-local view with padding in place of the bases
// TESClimate: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); opaque
// GetClimate, GetParentWorld, GetParentUseFlag: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence); same-named FNV methods, here with a bit-index flag argument
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesworldspace.cpp:533
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesworldspace.cpp:75
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesworldspace.cpp:880
#pragma once

#include <cstdint>

class TESClimate;

class TESWorldSpace
{
public:
    TESClimate* GetClimate();
    TESWorldSpace* GetParentWorld(std::uint32_t a_flag);
    bool GetParentUseFlag(std::uint32_t a_flag) const;

    std::uint8_t   pad00[0x98];
    TESClimate*    climate;  // 98
    std::uint8_t   padA0[0x2];
    std::uint16_t  parentUseFlags;  // A2
    std::uint8_t   padA4[0xB4];
    TESWorldSpace* parentWorld;  // 158
};
static_assert(sizeof(TESWorldSpace) == 0x160, "TESWorldSpace file-local view size");
