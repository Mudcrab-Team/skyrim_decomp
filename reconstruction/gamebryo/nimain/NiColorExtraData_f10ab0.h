// Source exposure: mixed (community PDB names; pinned-image observations).
// Code origin: original; partial declarations from observed payload accesses
// SPDX-License-Identifier: CC0-1.0
// NiColorExtraData: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiColorExtraData::Functionf10ab0: GUESS(low); address-based equality-query name
// NiColorExtraData::component0, NiColorExtraData::component1, NiColorExtraData::component2, NiColorExtraData::component3: OBSERVED; four scalar payload fields
#pragma once
#include <cstddef>
#include <cstdint>
class NiColorExtraData
{
public:
    bool Functionf10ab0(const NiColorExtraData* other) const;
    std::uint8_t unobserved00[0x18];
    float component0;
    float component1;
    float component2;
    float component3;
};
static_assert(offsetof(NiColorExtraData, component0) == 0x18, "scalar payload offset");
static_assert(offsetof(NiColorExtraData, component3) == 0x24, "last scalar payload offset");
