// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MagicItem, MagicItem::effects, Effect, Effect::baseEffect, EffectSetting: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN; layout read from the pinned image
// MagicItem::FindEffectMatchingDefault, Function14d670, MagicItem::effectCapacity, MagicItem::effectCount: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct EffectSetting;

struct Effect
{
    std::uint8_t unk00[0x10];
    EffectSetting* baseEffect;  // 0x10
};

EffectSetting* Function14d670();  // callee: matched leaf

class MagicItem
{
public:
    Effect* FindEffectMatchingDefault();  // compared: 0x151990

    std::uint8_t pad00[0x58];
    Effect** effects;              // 0x58
    std::uint32_t effectCapacity;  // 0x60
    std::uint32_t effectPad;       // 0x64
    std::uint32_t effectCount;     // 0x68
};
