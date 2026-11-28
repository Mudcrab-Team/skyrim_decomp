// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// PathFollowerStateTurnToAngle, PathFollowerStateTurnToAngle::sub_14112EA60: CRASHLOGGER_PDB(59818@2026.10.24)
// TurnToAngleParams, SetParameters, unk08, unk0C, unk10, unk14, unk18, unk1C: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct TurnToAngleParams
{
    std::uint32_t unk00;  // 00
    std::uint32_t unk04;  // 04
    std::uint32_t unk08;  // 08
    std::uint32_t unk0C;  // 0C
    std::uint32_t unk10;  // 10
    std::uint32_t unk14;  // 14
};
static_assert(sizeof(TurnToAngleParams) == 0x18, "TurnToAngleParams size");

class PathFollowerStateTurnToAngle
{
public:
    virtual ~PathFollowerStateTurnToAngle();
    void SetParameters(const TurnToAngleParams& a_params);  // compared: 0x1246900

    std::uint32_t unk08;  // 08
    std::uint32_t unk0C;  // 0C
    std::uint32_t unk10;  // 10
    std::uint32_t unk14;  // 14
    std::uint32_t unk18;  // 18
    std::uint32_t unk1C;  // 1C
};
static_assert(offsetof(PathFollowerStateTurnToAngle, unk1C) == 0x1C, "unk1C offset");
