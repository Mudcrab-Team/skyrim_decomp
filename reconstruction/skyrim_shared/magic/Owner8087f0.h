// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0x151d10 (skyrim_shared/magic/MagicItem_151d10): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Effect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN; layout read from the pinned image
// EffectVisitor: GUESS(low)
// Function8087f0, Owner8087f0: GUESS(low) STANDIN
#pragma once
#include "MagicItem_151d10.h"

class Owner8087f0
{
public:
    void Function8087f0(EffectVisitor* visitor);

    std::uint8_t pad00[0x8];
    Effect** effects;              // 0x58
    std::uint32_t effectCapacity;  // 0x60
    std::uint32_t effectPad;       // 0x64
    std::uint32_t effectCount;     // 0x68
};

