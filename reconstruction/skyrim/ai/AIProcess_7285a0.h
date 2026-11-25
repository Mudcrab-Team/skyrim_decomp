// Source exposure: mixed
// Code origin: declarations and layout reconstruction using the labelled sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// AIProcess, middleHigh, MiddleHighProcessData, deferredKillTimer, inDeferredKill: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// StartDeferredKill: SIBLING(fo4-private@1b765c70, author-permission)
// deferredKillState, deferredKillDuration, ResetDeferredKillTimer: GUESS(low); descriptive local names
// MiddleHighProcessData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once
#include <cstddef>
#include <cstdint>

struct MiddleHighProcessData
{
    std::uint8_t pad000[0x2D4];
    float deferredKillTimer;
    std::uint8_t pad2D8[0x20];
    std::uint32_t deferredKillState;
    std::uint8_t pad2FC[0x36];
    bool inDeferredKill;
};
static_assert(offsetof(MiddleHighProcessData, deferredKillTimer) == 0x2D4, "timer offset");
static_assert(offsetof(MiddleHighProcessData, deferredKillState) == 0x2F8, "state offset");
static_assert(offsetof(MiddleHighProcessData, inDeferredKill) == 0x332, "flag offset");

class AIProcess
{
public:
    void StartDeferredKill(bool fromScript);
    void ResetDeferredKillTimer(float duration)
    {
        if (middleHigh && middleHigh->deferredKillState > 0)
            middleHigh->deferredKillTimer = duration;
    }
    void* middleLow;
    MiddleHighProcessData* middleHigh;
};
static_assert(offsetof(AIProcess, middleHigh) == 8, "middle-high pointer offset");
extern float deferredKillDuration;
