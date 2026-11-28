// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: UIManagercefd60::UpdateCounter, treated as adapted: shaped like ControlMap::AllowTextInput (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/C/ControlMap.cpp:13, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// UIManagercefd60, UpdateCounter, unk00, counter, increment: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class UIManagercefd60
{
public:
    void UpdateCounter(bool increment);

    std::uint8_t unk00[0x128];  // 0x000
    std::uint8_t counter;       // 0x128
};
static_assert(offsetof(UIManagercefd60, counter) == 0x128, "counter offset");
