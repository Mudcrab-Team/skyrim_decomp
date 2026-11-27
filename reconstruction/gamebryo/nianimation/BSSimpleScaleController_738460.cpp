// Source exposure: mixed (community headers, the cited sibling and the pinned image listing).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x738460 BSSimpleScaleController::Update
// Adapted bodies: BSSimpleScaleController::Update follows fo4-private@1b765c70 src/Game/AI/BSSimpleScaleController.cpp
// Sibling source: fo4-private@1b765c70 src/Game/AI/BSSimpleScaleController.cpp:21
#include "BSSimpleScaleController_738460.h"

#include <cmath>

// Interpolates the target's local scale from the start scale to the end scale over the animation time.
void BSSimpleScaleController::Update(float)
{
    NiObjectNET* pTarget = target;
    lastTime = fCellAppTime;
    if (pTarget) {
        float time = fCellAppTime;
        float endTime = scaleAnimDuration;
        if (time <= endTime) {
            float start = startTime;
            if (endTime == start) {
                static_cast<NiAVObject*>(pTarget)->local.scale = fabsf(refScale);
            } else {
                static_cast<NiAVObject*>(pTarget)->local.scale = fabsf((time - start) / (endTime - start) * (refScale - scale3D) + scale3D);
            }
        }
    }
}
