// Source exposure: mixed (local pinned-image observations and community declarations).
// Code origin: original reconstruction; no external bodies used.
// SPDX-License-Identifier: GPL-3.0
// TweenMenuCameraState, targetAddedFOV, endingState: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// 0x8ff880 TweenMenuCameraState::Function8ff880
// Adapted bodies: none
#include "TweenMenuCameraState_8ff880.h"

void TweenMenuCameraState::Function8ff880()
{
    if (!endingState) {
        targetAddedRotX = g_tweenInitialX;
        targetAddedRotY = g_tweenInitialY;
        targetAddedFOV = 0.0f;
        endingState = true;
    }
}
