// Source exposure: mixed (pinned-image observations and community symbol declarations).
// Code origin: original; partial declarations from labelled naming sources
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectCELL, TESObjectCELL::GetGroupSubBlockKey: CRASHLOGGER_PDB(59818@2026.10.24)
// TESObjectCELL::GetGroupSubBlockKey: SYMBOLS(fo4-pdb)
// formID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ExteriorData, x, y, flags, exteriorData: STANDIN GUESS(low); descriptive names for observed fields
// GetExteriorX, GetExteriorY: GUESS(low); inferred inline coordinate access boundaries
#pragma once

#include <cstdint>
#include <cstddef>

class TESObjectCELL
{
public:
    struct ExteriorData { std::int32_t x; std::int32_t y; };
    std::uint32_t GetGroupSubBlockKey();
    std::int32_t GetExteriorX()
    {
        return exteriorData ? exteriorData->x : 0;
    }
    std::int32_t GetExteriorY()
    {
        return exteriorData ? exteriorData->y : 0;
    }
    std::uint8_t unknown00[0x14];
    std::uint32_t formID;
    std::uint8_t unknown18[0x28];
    std::uint16_t flags;
    std::uint8_t unknown42[0x26];
    ExteriorData* exteriorData;
};
static_assert(offsetof(TESObjectCELL, flags) == 0x40, "Observed flags offset");
static_assert(offsetof(TESObjectCELL, exteriorData) == 0x68, "Observed exterior data offset");
