// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSSceneActionTimer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BGSSceneActionTimer::Unk_0D, BGSSceneActionTimer::~BGSSceneActionTimer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown20: GUESS(low)
#pragma once

#include <cstdint>
#include "BGSSceneAction.h"

class BGSSceneActionTimer
{
public:
    BGSSceneActionTimer();
    virtual void Unk_0D();  // compared: 0x3ad170
    virtual ~BGSSceneActionTimer();  // compared: 0x3ad400 (scalar deleting destructor)
    // Unk_0DTarget: GUESS(low)
    void Unk_0DTarget();

    std::uint8_t unknown08[0x1c];  // 08
    // unknown24: GUESS(low)
    volatile std::uint32_t unknown24;  // 24
    // unknown28: GUESS(low)
    volatile std::uint16_t unknown28;  // 28
    std::uint8_t unknown2A[0x6];  // 2A
};
static_assert(sizeof(BGSSceneActionTimer) == 0x30, "BGSSceneActionTimer size");
