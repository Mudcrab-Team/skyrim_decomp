// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial layouts follow the pinned field accesses and cited declarations.
// Effect, Effect::EffectItem, ::effectItem, ::baseEffect, ::magnitude, ::area, ::duration: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Effect::GetMagnitude: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Effect::IsUsageMonitorEffect: CRASHLOGGER_PDB(59818@2026.10.24)
// EffectSetting, EffectSetting::data, EffectSettingData, ::flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// EffectSettingData::IsFlagSet, ::FlagBit, ::kNoMagnitudeBit: GUESS(low); bit number of CommonLib's kNoMagnitude mask
// Function14d670: GUESS(low)
#pragma once
#include <cstddef>
#include <cstdint>

class EffectSetting
{
public:
    struct EffectSettingData
    {
        enum FlagBit : std::uint32_t
        {
            kNoMagnitudeBit = 10
        };

        bool IsFlagSet(FlagBit a_flag) const { return ((flags >> a_flag) & 1) != 0; }

        std::uint32_t flags;  // 00
    };

    std::uint64_t     unk00[13];  // 00 - TESForm, TESFullName, BGSMenuDisplayObject, BGSKeywordForm bases and filter members
    EffectSettingData data;       // 68 - DATA
};
static_assert(offsetof(EffectSetting, data) == 0x68, "layout differs from CommonLibSSE-NG");

// Returns the effect setting the usage-monitor test compares against.
EffectSetting* Function14d670();

struct Effect
{
public:
    struct EffectItem
    {
        float         magnitude;  // 0
        std::uint32_t area;       // 4
        std::uint32_t duration;   // 8
    };

    float GetMagnitude() const;
    bool  IsUsageMonitorEffect() const;

    EffectItem     effectItem;  // 00 - EFIT
    std::uint32_t  unk0C;       // 0C
    EffectSetting* baseEffect;  // 10 - EFID
};
static_assert(offsetof(Effect, baseEffect) == 0x10, "layout differs from CommonLibSSE-NG");
