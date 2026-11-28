// Source exposure: binary-analysis (pinned image listing).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Calendar646040::GetDaysPassed, Calendar646040::GetHoursPassed, treated as adapted: shaped like Calendar::GetDaysPassed and Calendar::GetHoursPassed (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/C/Calendar.cpp:67 and src/RE/C/Calendar.cpp:84, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GlobalValue646040, Calendar646040, GetDaysPassed, GetHoursPassed, unk00, value, gameDaysPassed: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct GlobalValue646040
{
    std::uint8_t unk00[0x34];  // 0x00
    float value;               // 0x34
};
static_assert(offsetof(GlobalValue646040, value) == 0x34, "GlobalValue646040 value offset");

class Calendar646040
{
public:
    float GetDaysPassed() const
    {
        return gameDaysPassed != nullptr ? gameDaysPassed->value : 1.0f;
    }

    std::uint32_t GetHoursPassed() const;

    std::uint64_t unk00[5];             // 0x00
    GlobalValue646040* gameDaysPassed;  // 0x28
};
static_assert(offsetof(Calendar646040, gameDaysPassed) == 0x28, "gameDaysPassed offset");
