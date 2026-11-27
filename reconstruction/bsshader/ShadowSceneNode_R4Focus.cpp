// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original reconstruction from the pinned image listing
// 0x1510eb0 ShadowSceneNode::SetFocusFrustum
#include "ShadowSceneNode_R4Focus.h"

// SetFocusFrustum: GUESS(low); no public name. Without a caller object it builds a default one that covers the whole scene.
void ShadowSceneNode::SetFocusFrustum(FocusFrustum* a_frustum)
{
    MemoryContextScope scope(0x1A);
    if (!a_frustum) {
        focusFrustum = new FocusFrustum;
        FocusFrustum* frustum = focusFrustum;
        frustum->limitA = 500000.0f;
        frustum->limitB = 500000.0f;
        frustum->scaleA = 1.0f;
        frustum->scaleB = 1.0f;
        frustum->limitC = 500000.0f;
        frustum->limitD = 500000.0f;
        frustum->centreA = FocusPoint(0.5f, 0.5f, 0.5f);
        focusFrustum->centreB = FocusPoint(0.5f, 0.5f, 0.5f);
        focusFrustum->centreC = FocusPoint(0.5f, 0.5f, 0.5f);
    } else {
        focusFrustum = a_frustum;
    }
}
