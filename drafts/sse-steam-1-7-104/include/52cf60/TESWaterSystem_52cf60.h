// Exposure detail: (community declarations; pinned-image observations).
// Source exposure: mixed
// Code origin: original; observed layout and labelled naming sources
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESWaterSystem, TESWaterReflections, flags, waterReflections: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// FindReflection, reflectionCount: GUESS(low)

#pragma once
#include <cstdint>
#include <cstddef>

class TESWaterReflections {
public:
    std::uint8_t unknown00[0x10];
    std::uint32_t flags;
};
static_assert(offsetof(TESWaterReflections, flags) == 0x10, "flags offset");

class TESWaterSystem {
public:
    TESWaterReflections* FindReflection(std::uint8_t interior);
    std::uint8_t unknown00[0x38];
    TESWaterReflections** waterReflections;
    std::uint32_t capacity;
    std::uint32_t unknown44;
    std::uint32_t reflectionCount;
};
static_assert(offsetof(TESWaterSystem, waterReflections) == 0x38, "array offset");
static_assert(offsetof(TESWaterSystem, reflectionCount) == 0x48, "count offset");
