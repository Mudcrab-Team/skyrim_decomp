// Source exposure: mixed (community PDB names; pinned-image observations).
// Code origin: original; partial declarations from observed payload accesses
// SPDX-License-Identifier: CC0-1.0
// NiVectorExtraData: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiVectorExtraData::Functionf1a1d0: GUESS(low); address-based equality-query name
// NiVectorExtraData::component0, NiVectorExtraData::component1, NiVectorExtraData::component2, NiVectorExtraData::component3: OBSERVED; four scalar payload fields
#pragma once
#include <cstddef>
#include <cstdint>
class NiVectorExtraData
{
public:
    bool Functionf1a1d0(const NiVectorExtraData* other) const;
    std::uint8_t unobserved00[0x18];
    float component0;
    float component1;
    float component2;
    float component3;
};
static_assert(offsetof(NiVectorExtraData, component0) == 0x18, "scalar payload offset");
static_assert(offsetof(NiVectorExtraData, component3) == 0x24, "last scalar payload offset");
