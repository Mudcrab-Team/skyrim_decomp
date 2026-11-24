// Source exposure: mixed (community declarations, sibling shape and the pinned image listing).
// Code origin: adapted from the cited sibling body; layout and names checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/EffectItem.cpp:24
// Effect, Effect::EffectItem, magnitude, area, duration, baseEffect, cost, conditions: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Effect::SetCost: CRASHLOGGER_PDB(59818@2026.10.24)
// Effect::Initialize: GUESS(medium); the sibling names this function EffectItem::Initialize
// EffectSetting: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown20: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class EffectSetting;

class Effect
{
public:
    struct EffectItem
    {
        float magnitude;  // 0
        std::uint32_t area;  // 4
        std::uint32_t duration;  // 8
    };

    void SetCost();
    void Initialize(EffectSetting* a_effect, float a_magnitude, std::uint32_t a_duration, std::uint32_t a_area);  // compared: 0x148c90

    EffectItem effectItem;  // 00
    std::uint32_t pad0C;  // 0C
    EffectSetting* baseEffect;  // 10
    float cost;  // 18
    std::uint32_t pad1C;  // 1C
    std::uint8_t unknown20[0x8];  // 20
};
static_assert(sizeof(Effect) == 0x28, "Effect size");
