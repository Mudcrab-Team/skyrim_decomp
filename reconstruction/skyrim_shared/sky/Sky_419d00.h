// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original reconstruction from the pinned image listing; community names and offsets as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sky::CalcSunriseEnd, Sky::CalcSunsetBegin: CRASHLOGGER_PDB(59818@2026.10.24)
// Sky, Sky::currentClimate, Sky::flags, Sky::Flags::kUpdateSunriseEnd, ::kUpdateSunsetBegin: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG's flags is an enumeration, here its 32-bit value
// TESClimate, TESClimate::timing: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the two timing bytes at 79 and 7A
// sunriseEnd, sunsetBegin: GUESS(low); the byte names come from NG's climate timing
// unk00, unk48: GUESS(low); unread ranges
#pragma once

#include <cstdint>
#include <cstddef>

struct TESClimate
{
    std::uint8_t unk00[0x79];
    std::uint8_t sunriseEnd;   // 79
    std::uint8_t sunsetBegin;  // 7A
};

class Sky
{
public:
    enum Flags : std::uint32_t
    {
        kUpdateSunriseEnd = 1u << 10,
        kUpdateSunsetBegin = 1u << 11,
    };

    float CalcSunriseEnd();   // compared: 0x419d00
    float CalcSunsetBegin();  // compared: 0x419d50

    std::uint8_t unk00[0x40];
    TESClimate* currentClimate;  // 40
    std::uint8_t unk48[0x1dc - 0x48];
    std::uint32_t flags;         // 1DC
};
static_assert(offsetof(Sky, flags) == 0x1dc, "Sky flags offset");
