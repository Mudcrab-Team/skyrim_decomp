// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MagicItem, MagicItem::effects, Effect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN; layout read from the pinned image
// MagicItem::VisitEffects, EffectVisitor, EffectVisitor::unk00, EffectVisitor::Visit, MagicItem::effectCapacity, MagicItem::effectCount: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Effect;

class EffectVisitor
{
public:
    virtual void unk00();
    virtual std::int32_t Visit(Effect* effect);  // slot 1
};

class MagicItem
{
public:
    void VisitEffects(EffectVisitor* visitor);  // compared: 0x151d10

    std::uint8_t pad00[0x58];
    Effect** effects;              // 0x58
    std::uint32_t effectCapacity;  // 0x60
    std::uint32_t effectPad;       // 0x64
    std::uint32_t effectCount;     // 0x68
};
