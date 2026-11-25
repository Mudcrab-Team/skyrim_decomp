// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Code origin: original declarations with labelled community and sibling names. Stamped as a twin of matched 0x5ba090 (skyrim/magic/ValueModifierEffect): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/StimpakEffect.cpp:6
// Function159af70, Owner159af70: GUESS(low) STANDIN
// unknown00, unknown60, unknown80: GUESS(low) STANDIN
#pragma once
#include "ValueModifierEffect.h"

class Owner159af70 {
public:
    void Function159af70(std::uint32_t value);
    void Function5bcba0(const void* a_location);
    void Function5bb320(TESBoundObject* a_source, bool a_enchanting);
    void Function5bb990(bool a_enabled);
private:
    std::uint8_t unknown00[0x58];
    TESBoundObject* source;
    std::uint8_t unknown60[0x1C];
    std::uint32_t flags;
    std::uint8_t unknown80[0x118];
    std::uint32_t actorValue;
};

