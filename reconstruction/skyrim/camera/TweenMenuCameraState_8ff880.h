// Source exposure: mixed (local pinned-image observations and community declarations).
// Code origin: original reconstruction; names/layout from the labelled community declaration.
// SPDX-License-Identifier: GPL-3.0
// Declaration names/layout adapted from powerof3/CommonLibSSE include/RE/T/TweenMenuCameraState.h.
// TweenMenuCameraState, currentAddedFOV, targetAddedFOV, endingState: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// TweenMenuCameraState::Function8ff880: GUESS(low)
// targetAddedRotX, targetAddedRotY, g_tweenInitialX, g_tweenInitialY: GUESS(low) STANDIN; observed components of the community targetAddedRot member.
#pragma once
#include <cstdint>
#include <cstddef>

extern float g_tweenInitialX;
extern float g_tweenInitialY;
class TweenMenuCameraState
{
public:
    void Function8ff880();
    std::uint8_t unknown00[0x3c];
    float targetAddedRotX;
    float targetAddedRotY;
    float currentAddedFOV;
    float targetAddedFOV;
    bool endingState;
};
static_assert(offsetof(TweenMenuCameraState, targetAddedRotX) == 0x3c, "targetAddedRotX offset");
static_assert(offsetof(TweenMenuCameraState, endingState) == 0x4c, "endingState offset");
