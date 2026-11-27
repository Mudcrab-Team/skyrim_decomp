// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original reconstruction from the pinned image listing; community names and offsets as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sky::Function40d370: GUESS(low); the name comes from the inventory
// Sky, Sky::currentClimate: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG's layout
// TESClimate, TESClimate::timing: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the moon phase byte at 7D
// moonPhaseLength: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; the low six bits are the phase length
// Calendar, Calendar::Function646000, g_calendar, g_moonPhase: STANDIN GUESS(low); names made up for the callee at 0x646000 and two globals
// unk00, unk78: GUESS(low); unread ranges
#pragma once

#include <cstdint>
#include <cstddef>

struct TESClimate
{
    std::uint8_t unk00[0x7d];
    std::uint8_t moonPhaseLength;  // 7D
};

class Calendar
{
public:
    std::uint32_t Function646000();  // callee at 0x646000, not compared
};

extern Calendar* g_calendar;
extern std::uint32_t g_moonPhase;

class Sky
{
public:
    bool Function40d370();  // compared: 0x40d370

    std::uint8_t unk00[0x40];
    TESClimate* currentClimate;  // 40
};
static_assert(offsetof(Sky, currentClimate) == 0x40, "layout");
