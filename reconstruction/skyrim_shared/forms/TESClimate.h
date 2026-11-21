// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Base form: shared header declarations/TESForm.h for TESForm.
// TESClimate, TESClimate::InitializeData, TESClimate::~TESClimate, TESClimate::Load: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESClimate::Timing, Timing::Interval, ::sunrise, ::sunset, ::begin, ::end, ::volatility, ::moonPhaseLength: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG declares an 8-byte Timing, the image clears and sets its first six bytes
// unknown20, unknown7E: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include "declarations/TESForm.h"

class TESClimate : public TESForm
{
public:
    ~TESClimate() override;  // 00
    virtual void InitializeData();  // compared: 0x2a5c10  // slot 04
    bool Load(TESFile* a_mod) override;  // 06

    std::uint8_t unknown20[0x58];  // 20
    struct Timing
    {
        struct Interval
        {
            std::uint8_t begin;  // 0
            std::uint8_t end;  // 1
        };

        Interval sunrise;  // 0
        Interval sunset;  // 2
        std::uint8_t volatility;  // 4
        std::uint8_t moonPhaseLength;  // 5
    };
    static_assert(sizeof(Timing) == 0x6, "Timing size");

    Timing timing;  // 78
    std::uint8_t unknown7E[0x2];  // 7E
};
static_assert(sizeof(TESClimate) == 0x80, "TESClimate size");
